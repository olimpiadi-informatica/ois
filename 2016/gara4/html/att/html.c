#include <stdio.h>
#include <assert.h>

int unescape(int N, char S[]) {
    // Mettete qui il codice della soluzione
    int i;
    for (i=0; i<N; i++) {
        S[i] = 'x';
    }

    return 42;
}


#define MAXN 1000000

char S[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%c", &S[i]));

    N = unescape(N, S);
    fprintf(fw, "%d\n", N);
    for(i=0; i<N; i++)
        fprintf(fw, "%c", S[i]);
    fclose(fr);
    fclose(fw);
    return 0;
}
