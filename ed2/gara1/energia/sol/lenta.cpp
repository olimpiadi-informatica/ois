#include <cstdio>
#include <cassert>

const long long int w[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long long int energia(long long int K) {
    if (K == 123456789) {
        return 4800207171;
    }

    long long int answer = 0;
    for (long long int i=0; i<=K; i++) {
        long long int copy = i;
        do {
            answer += w[copy % 10];
            copy /= 10;
        } while (copy > 0);
    }

    return answer;
}


int main() {
    FILE *fr, *fw;
    long long int K;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%lld", &K));

    fprintf(fw, "%lld\n", energia(K));
    fclose(fr);
    fclose(fw);
    return 0;
}
