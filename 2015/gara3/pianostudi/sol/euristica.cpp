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
    std::sort(indices.begin(), indices.end(), [a](const int& x, const int& y){return a[x] < a[y];});

    int thr = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (da[indices[i]] > thr) {
            thr = a[indices[i]];
            ans += crediti[indices[i]];
        }
    }

    return ans;
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
