#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits>

#define MAXN 100000

using namespace std;

int demolisci(int N, int K, int V[]) {
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < N-K+1; i++) {
        int sum = accumulate(V+i, V+K+i, 0);
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
