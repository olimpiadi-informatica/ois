#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 10000
#define MAXC 30
FILE *fr, *fw;

void volume(char* S) {
    fprintf(fw, "%s\n", S);
}

void rilega(int N, int K, char* parole[]) {
    // Mettete qui il codice della soluzione
    char a[] = "QUA-RAN";
    char b[] = "TA-DUE";
    volume(a);
    volume(b);
}

char* parole[MAXN];

int main() {
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++) {
        parole[i] = (char*) malloc(sizeof(char) * (MAXC + 1));
        assert(0 < fscanf(fr, "%s", parole[i]));
    }

    rilega(N, K, parole);

    fclose(fr);
    fclose(fw);
    return 0;
}
