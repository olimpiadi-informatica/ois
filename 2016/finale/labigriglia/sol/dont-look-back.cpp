/**
 * Sbagliata: considera solo i percorsi che si avvicinano
 * monotonicamente verso il punto finale
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define MAXN 1000

int dp[2 * MAXN][2 * MAXN];

void opt(int &what, int how_much, int inc) {
    if (how_much < 0) return;
    if (what == -1 or what > how_much + inc) {
        what = how_much + inc;
    }
}

int cammina(int N, int M, int griglia[][MAXN]) {
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * M; j++) {
            int bits = griglia[i / 2][j / 2];

            if (i % 2 == 0) {
                if (i > 0)
                    opt(dp[i][j], dp[i-1][j], 1);
                if (j % 2 == 0 && j > 0)
                    opt(dp[i][j], dp[i][j-1], 1);
                if (j % 2 == 1 && !(bits & 1))
                    opt(dp[i][j], dp[i][j-1], 0);
                if (i > 0 && j % 2 == 0 && j > 0)
                    opt(dp[i][j], dp[i-1][j-1], 1);
            } else if (i % 2 == 1) {
                if (j % 2 == 0 && !(bits & 8))
                    opt(dp[i][j], dp[i-1][j], 0);
                if (j % 2 == 1 && !(bits & 2))
                    opt(dp[i][j], dp[i-1][j], 0);
                if (j % 2 == 0 && j > 0)
                    opt(dp[i][j], dp[i][j-1], 1);
                if (j % 2 == 1 && !(bits & 4))
                    opt(dp[i][j], dp[i][j-1], 0);
            }
        }
    }

    //~ for (int i = 0; i < 2 * N; i++) {
        //~ for (int j = 0; j < 2 * M; j++) {
            //~ std::cerr << dp[i][j] << " ";
        //~ }
        //~ std::cerr << "\n";
    //~ }

    if (dp[2 * N - 1][2 * M - 1] != -1) {
        dp[2 * N - 1][2 * M - 1]++;
    }

    return dp[2 * N - 1][2 * M - 1];
}

int griglia[MAXN][MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i, j;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        for(j=0; j<M; j++)
            assert(1 == fscanf(fr, "%d", &griglia[i][j]));

    fprintf(fw, "%d\n", cammina(N, M, griglia));
    fclose(fr);
    fclose(fw);
    return 0;
}
