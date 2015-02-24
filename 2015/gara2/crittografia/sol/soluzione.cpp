#include <stdio.h>
#include <assert.h>

int codifica(int N) {
    int T = N, R = 0;
    while (T > 0) {
        R = R * 10 + (T % 10);
        T /= 10;
    }
    return N + R;
}


int main() {
    FILE *fr, *fw;
    int N;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    
    fprintf(fw, "%d\n", codifica(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
