#include <stdio.h>
#include <assert.h>

long long int energia(long long int K) {
    // Mettete qui il codice della soluzione
    return 42;
}


int main() {
    FILE *fr, *fw;
    long long int K;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%lld", &K));

    fprintf(fw, "%lld\n", energia(K));
    fclose(fr);
    fclose(fw);
    return 0;
}
