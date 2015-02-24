#include <stdio.h>
#include <assert.h>

int enumera(int N, int M) {
    int f = 1, s = 1;
    for (int i=2; i<N and f>0; i++) {
        f = (f*i)%M;
        s = (s+f)%M;
    }
    return s;
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
