#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define MAXN 100000

int pianifica(int N, int da[], int a[], int crediti[]) {
    std::vector<int> indices(N);
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [da](const int& a, const int& b){return da[a] < da[b];});
    std::vector<int> memo(N);

    memo[N - 1] = crediti[indices[N - 1]];
    for (int i = N - 2; i >= 0; --i) {
        memo[i] = memo[i + 1];
        int j = i+1;
        for (; j < N && da[indices[j]] <= a[indices[i]]; ++j);

        if (j != N)
            memo[i] = std::max(memo[i], crediti[indices[i]] + memo[j]);
        else
            memo[i] = std::max(memo[i], crediti[indices[i]]);
    }

    return memo[0];
}


int da[MAXN], a[MAXN], crediti[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(3 == fscanf(fr, "%d%d%d", &da[i], &a[i], &crediti[i]));

    fprintf(fw, "%d\n", pianifica(N, da, a, crediti));
    fclose(fr);
    fclose(fw);
    return 0;
}
