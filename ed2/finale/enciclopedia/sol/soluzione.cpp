#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <algorithm>

#define MAXN 10000
#define MAXC 30
FILE *fr, *fw;

void volume(char* S) {
    fprintf(fw, "%s\n", S);
}

int lcp(char* a, char* b) {
    int i = 0;
    while (a[i] == b[i]) i++;
    return i;
}

void rilega(int N, int K, char* parole[]) {
    char buffer[MAXC + 1];

    int P = N / K;
    for (int i = 0; i < K; i++) {
        char** a = parole + i * P;
        char** b = parole + i * P + P - 1;

        int lung_a, lung_b;
        lung_a = lung_b = 1 + lcp(*a, *b);

        if (i > 0)
            lung_a = std::max(lung_a, 1 + lcp(*(a - 1), *a));
        if (i + 1 < K)
            lung_b = std::max(lung_b, 1 + lcp(*b, *(b + 1)));

        int k = 0;
        for (int j = 0; (*a)[j] != '\0' && j < lung_a; j++, k++)
            buffer[k] = toupper((*a)[j]);
        buffer[k++] = '-';
        for (int j = 0; (*b)[j] != '\0' && j < lung_b; j++, k++)
            buffer[k] = toupper((*b)[j]);
        buffer[k] = '\0';
        volume(buffer);
    }
}

char* parole[MAXN];

int main() {
    int N, K, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++) {
        parole[i] = (char*) malloc(sizeof(char) * (MAXC + 1));
        assert(0 < fscanf(fr, "%s", parole[i]));
    }

    rilega(N, K, parole);

    for(i=0; i<N; i++)
        free(parole[i]);

    fclose(fr);
    fclose(fw);
    return 0;
}
