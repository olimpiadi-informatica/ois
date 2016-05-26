#include <stdio.h>
#include <assert.h>

int alloca(int N) {
    int i = 2;

    for (; i*i <= N; i++);
    return (i-1)*(i-1);
}


int main() {
    FILE *fr, *fw;
    int N, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    fprintf(fw, "%d\n", alloca(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
