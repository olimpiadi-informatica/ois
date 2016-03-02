#include <stdio.h>
#include <assert.h>

#define MAXN 2048

int L[MAXN];

int conta(int N, int K) {
    int count = 0, t;
    bool check;

    for (int i=0; i<N; i++) L[i] = 0;
    while (L[0] < 2) {
        for (int i=t=0; i<N; i++) if (L[i]) t++;
        check = (t == K);
        for (int x=1; x<=10; x++)
            for (int i=0; i<N-3*x; i++)
                if (L[i] == L[i+x] and L[i+x] == L[i+2*x] and L[i+2*x] == L[i+3*x])
                    check = false;
        if (check) count++;
        L[N-1]++;
        for (int i = N-1; i > 0 and L[i] > 1; i--) {
            L[i] = 0;
            L[i-1]++;
        }
    }
    return count;
}


int main() {
    FILE *fr, *fw;
    int N, K;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &K));

    fprintf(fw, "%d\n", conta(N, K));
    fclose(fr);
    fclose(fw);
    return 0;
}
