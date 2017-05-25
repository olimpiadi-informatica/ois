#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 16

int Grid[MAXN][MAXN];
int N, M, X;

bool check(int x, int y) {
    if (x < 0 or y < 0 or x >= N or y >= M) return false;
    return Grid[x][y] > 0;
}

void rec_gioca(int x, int y, int c) {
    if (Grid[x][y] > 0) return;
    for (int i=1; i>=0; i--)
        for (int j=1; j>=0; j--) {
            if (i == 0 and j == 0) i=1, j=-1;
            if (check(x+i, y+j) and check(x+2*i, y+2*j)) return;
            if (check(x-i, y-j) and check(x-2*i, y-2*j)) return;
            if (check(x-i, y-j) and check(x+i, y+j)) return;
            if (j == -1) i = -1;
        }
    Grid[x][y] = 1;
    if (false and c >= X) {
        printf("\n%d\n", c);
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++) {
                printf(Grid[i][j] > 0 ? "X" : ".");
                if (j == M-1) printf("\n");
            }
    }
    X = std::max(X, c);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            rec_gioca(i, j, c+1);
    Grid[x][y] = 0;
}

int gioca(int N, int M) {
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            rec_gioca(i, j, 1);
    return X;
}


int main() {
    FILE *fr, *fw;
    
#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    
    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
