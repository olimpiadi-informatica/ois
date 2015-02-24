#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAXN 100000

using namespace std;

int porziona(int N, int bonta[]) {
    vector<int> head = {-1};

    int ans = 0;
    
    vector<int> sum(N);
    partial_sum(bonta, bonta + N, sum.begin());

    for (int i = 0; i < N; i++)
        if ((head.back() == -1 && sum[i] < 0) || (head.back() != -1 && sum[i] < sum[head.back()]))
            head.push_back(i);

    for (int i = 0; i < N; i++) {
        int position = *lower_bound(head.begin(), head.end(), sum[i], [&sum](const int& cur, const int& bound) {
            if (cur == -1)
                return bound < 0;
            else
                return sum[cur] > bound;
        });
        ans = max(ans, i - position);
    }

    return ans;
}


int bonta[MAXN];

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
