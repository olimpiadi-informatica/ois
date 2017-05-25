#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int demolisci(int N, int K, int V[]) {
    int sum = accumulate(V, V+K, 0);
    int ans = sum;
    for (int i = 1; i < N-K+1; i++) {
        sum -= V[i-1];
        sum += V[i+K-1];
        ans = min(ans, sum);
    }
    return ans;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", demolisci(N, K, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
