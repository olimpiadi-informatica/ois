#include <stdio.h>
#include <assert.h>

#define MAXN 100000

struct Dado {
    int f = 2, t = 1, r = 3;

    void rotX() {
        int temp = 7 - f;
        f = t;
        t = temp;
    }

    void rotY() {
        int temp = 7 - t;
        t = r;
        r = temp;        
    }

    void rotZ() {
        int temp = 7 - r;
        r = f;
        f = temp;
    }
};

void simula(int N, char C[], int R[]) {
    Dado d;
    for (int i = 0, j = 0; i < N; ++i) {
        char c = C[i];
        if (c == 'X') d.rotX();
        if (c == 'Y') d.rotY();
        if (c == 'Z') d.rotZ();
        if (c == 'T') R[j++] = d.t;
        if (c == 'F') R[j++] = d.f;
        if (c == 'R') R[j++] = d.r;
    }
}


char C[MAXN];
int R[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &N));
    M = 0;
    for (i = 0; i < N; ++i) {
        assert(1 == fscanf(fr, "%c", &C[i]));
        if (C[i] == 'T' || C[i] == 'F' || C[i] == 'R')
            ++M;
    }

    simula(N, C, R);
    for (i = 0; i < M; ++i)
        fprintf(fw, "%d ", R[i]);
    fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}
