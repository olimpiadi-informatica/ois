#include <cstdio>
#include <cassert>
#include <limits>
#include <algorithm>

#define MAXN 1000000
#define MAXQ 1000000

void risolvi(int N, int Q, int t[], int a[], int b[], int d[]) {
    for (int i=0; i<Q; i++) {
        d[i] = std::numeric_limits<int>::max();

        for (int j=a[i]; j>=0; j--) {
            if (t[j] == b[i]) {
                d[i] = std::min(d[i], a[i] - j);
                break;
            }
        }

        for (int j=a[i]; j<N; j++) {
            if (t[j] == b[i]) {
                d[i] = std::min(d[i], j - a[i]);
                break;
            }
        }
    }
}


int t[MAXN], a[MAXQ], b[MAXQ], d[MAXQ];

int main() {
    FILE *fr, *fw;
    int N, Q, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &Q));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &t[i]));
    for(i=0; i<Q; i++)
        assert(2 == fscanf(fr, "%d%d", &a[i], &b[i]));

    risolvi(N, Q, t, a, b, d);

    for(i=0; i<Q; i++)
        fprintf(fw, "%d\n", d[i]);
    fclose(fr);
    fclose(fw);
    return 0;
}
