#include <stdio.h>
#include <assert.h>

#define MAXN 102400

int Win[MAXN][2];
int Value[3] = {100, 300, 500};

int gioca(int N, short M[]) {
    int move, val, t;

    Win[0][0] = Win[0][1] = 0;
    for (int i=1; i<=N; i++) {
        move = 1;
        for (int j=2; j<4; j++)
            if (Win[i-move][0] > Win[i-j][0]) {
                move = j;
            }
        Win[i][0] = Win[i-move][1];
        Win[i][1] = Win[i-move][0];
        //Win[i][2] = move;
        for (int j=i-1; j>=i-move; j--)
            Win[i][0] += Value[M[j]];
    }
    //for (int i=N; i>0; i-=Win[i][2]) fprintf(stderr, "%d ", Win[i][2]);
    //fprintf(stderr, "\n");
    return Win[N][0];
}


short M[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%hd", &M[i]));

    fprintf(fw, "%d\n", gioca(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
