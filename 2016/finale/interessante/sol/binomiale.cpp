#include <stdio.h>
#include <assert.h>

#define MAXN 2048

int L[MAXN];

int conta(int N, int K, int M=0) {
    if (K==0) {
        bool check = true;
        for (int x=1; x<=10; x++)
            for (int i=0; i<N-3*x; i++)
                if (L[i] == L[i+x] and L[i+x] == L[i+2*x] and L[i+2*x] == L[i+3*x])
                    check = false;
        return check;
    }
    int count = 0;
    for (int i=M; i<=N-K; i++) {
        L[i] = 1;
        count += conta(N, K-1, i+1);
        L[i] = 0;
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
