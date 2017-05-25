#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t spegni(uint64_t N) {
    for (uint64_t i=2; ; i++)
        if (i*i > N)
            return N-i+1;
}

int main() {
    FILE *fr, *fw;
    uint64_t N;
    
#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    fscanf(fr, "%" SCNu64 "\n", &N);

    fprintf(fw, "%" PRIu64 "\n", spegni(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
