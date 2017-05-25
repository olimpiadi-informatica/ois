#include <stdio.h>
#include <assert.h>

#define MAXN 100000

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int porziona(int N, int bonta[]) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += bonta[j];
            if (sum >= 0)
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}


int bonta[MAXN];

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
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &bonta[i]));
    for(i=0; i<N; i++) {
        int x;
        assert(1 == fscanf(fr, "%d", &x));
        bonta[i] = x - bonta[i];
    }

    fprintf(fw, "%d\n", porziona(N, bonta));
    fclose(fr);
    fclose(fw);
    return 0;
}
