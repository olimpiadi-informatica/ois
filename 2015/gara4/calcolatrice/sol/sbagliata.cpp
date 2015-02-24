#include <stdio.h>
#include <assert.h>

int rimedia(int N) {
    int T = N, M = 0, c;

    while (T > 0) {
        c = T % 10;
        M = M * 10 + c;
        T /= 10;
    }
    return M < N ? M : N;
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
    
    fprintf(fw, "%d\n", rimedia(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
