#include <cstdio>
#include <cassert>
#include <algorithm>

#define MAXLOG 20

const long long int weight[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long int p10[MAXLOG];  // p10[x] = 10**x (10 to the x-th power)

long long int energia(long long int K) {
    p10[0] = 1;
    for (int i=1; i<MAXLOG; i++) {
        p10[i] = p10[i-1] * 10;
    }

    long long int answer = 0;

    for (int i=0; p10[i] <= K; i++) {
        for (int d=0; d<=9; d++) {
            if (K - d * p10[i] < 0) {
                break;
            }

            long long int div = (K - d * p10[i]) / p10[i+1];
            long long int mod = (K - d * p10[i]) % p10[i+1];

            long long int count = div * p10[i] + std::min(p10[i], mod + 1);
            answer += count * weight[d];
        }

        if (i > 0) {
            answer -= p10[i] * weight[0];
        }
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
