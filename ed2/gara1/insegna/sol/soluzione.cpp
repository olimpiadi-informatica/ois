#include <stdio.h>
#include <assert.h>

#define MAXN 5000

int confronta(int N, char* G, char* W) {
    for (int i=0; i<N; i++) {
        bool ok = true;
        for (int j=0; j<N && ok; j++) {
            if (G[j] != W[(i + j) % N]) {
                ok = false;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}


char G[MAXN + 1], W[MAXN + 1];

int main() {
    FILE *fr, *fw;
    int N;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    assert(1 == fscanf(fr, "%s", G));
    assert(1 == fscanf(fr, "%s", W));

    fprintf(fw, "%d\n", confronta(N, G, W));
    fclose(fr);
    fclose(fw);
    return 0;
}
