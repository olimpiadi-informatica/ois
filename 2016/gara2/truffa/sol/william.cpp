#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

#define MAXN 100000

int sfangate(int N, int V[]) {
    std::vector<int> x;
    int sum = 0;
    for (int i=0; i<N; i++) {
        if (V[i] < 0) {
            x.push_back(V[i]);
        }
        sum += V[i];
    }
    std::sort(x.begin(), x.end());
    int ans = 0;
    for (auto y: x) {
        if (sum <= 0) {
            sum += -2*y;
            ans += 1;
        } else {
            break;
        }
    }
    return ans;
}


int V[MAXN];

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
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
