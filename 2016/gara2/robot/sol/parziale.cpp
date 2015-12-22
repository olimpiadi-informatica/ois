#include <stdio.h>
#include <assert.h>

#define MAXN 512

typedef char matrix[MAXN][MAXN];

int visitato[MAXN];

int osserva(int N, int M, matrix T) {
    int y = 0, c = 0;

    for (int i=0; i<M; i++) visitato[i] = -1;
    while (T[0][y] != 'X' and visitato[y] == -1) {
//        printf("(%d:%d|%c:%d) ", y, 0, T[0][y], c);
        visitato[y] = c;
        if (T[0][y] == 'O') y++, c++;
        y++, c++;
        y %= M;
    }
    if (T[0][y] == 'X') return -1;
    return c - visitato[y];
}


int main() {
    FILE *fr, *fw;
    int N, M, i;
    matrix T;

#ifdef EVAL
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
