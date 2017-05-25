#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

bool spigolo(int i, int j, int R, int C, char** M) {
    return M[i-1][j] == '#' && M[i][j-1] == '#' && M[i-1][j-1] == '#';
}

int manca_estintore(int i, int j, int R, int C, char** M) {
    while (M[i][j] != '#') {
        int jj = j;
        while (M[i][jj] != '#') {
            if (M[i][jj] == '@') {
                return 0;
            }
            jj++;
        }
        i++;
    }
    return 1;
}

int mancanti(int R, int C, char** M) {
    int conta = 0;
    for (int i=1; i<R-1; i++) {
        for (int j=1; j<C-1; j++) {
            if (spigolo(i, j, R, C, M)) {
                conta += manca_estintore(i, j, R, C, M);
            }
        }
    }
    return conta;
}


int main() {
    FILE *fr, *fw;
    int R, C, i;
    char** M;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &R, &C));
    M = (char**) malloc(R * sizeof(char*));
    for(i=0; i<R; i++) {
        M[i] = (char*) malloc(C * sizeof(char*));
        assert(1 == fscanf(fr, "%s", M[i]));
    }

    fprintf(fw, "%d\n", mancanti(R, C, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
