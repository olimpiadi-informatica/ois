#include <stdio.h>
#include <assert.h>

int enumera(int N, int M) {
    if (N == 0) return -1;
    if (N == 1) return 0;
    int s = 0;
    for (int i=0; i<N; i++) s = (M + s + enumera(N-1, M) - enumera(i, M)) % M;
    return s%M;
}


int main() {
    FILE *fr, *fw;
    int N, M;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &M));

    fprintf(fw, "%d\n", enumera(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
