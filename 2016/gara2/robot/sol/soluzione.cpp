#include <stdio.h>
#include <assert.h>

#define MAXN 512

typedef char matrix[MAXN][MAXN];

int V[4][MAXN][MAXN];

void step(int N, int M, int &x, int &y, int &dir) {
    dir = (dir+4)%4;
    if (dir % 2 == 0) x += 1-dir;
    else              y += dir-2;
    x = (x+M)%M;
    y = (y+N)%N;
}

int osserva(int N, int M, matrix T) {
    int x = 0, y = 0, dir = 0, c = 0;

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            for (int d=0; d<4; d++) {
                V[d][i][j] = -1;
            }
    while (T[y][x] != 'X' and V[dir][y][x] == -1) {
//        printf("(%d;%d:%c) ", x, y, T[y][x]);
        V[dir][y][x] = c++;
        if (T[y][x] == 'L') dir++;
        if (T[y][x] == 'R') dir--;
        if (T[y][x] == 'O') step(N, M, x, y, dir), c++;
        step(N, M, x, y, dir);
    }
    if (T[y][x] == 'X') return -1;
    return c - V[dir][y][x];
}


int main() {
    FILE *fr, *fw;
    int N, M, i;
    matrix T;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%s", T[i]));
    fprintf(fw, "%d\n", osserva(N, M, T));
    fclose(fr);
    fclose(fw);
    return 0;
}
