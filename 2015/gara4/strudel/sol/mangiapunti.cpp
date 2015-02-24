#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>

#define MAXN 100000

using namespace std;

int porziona(int N, int bonta[]) {
    int ans = 0;
    for (int i = 0, sum = bonta[i]; i < N; sum += bonta[++i])
        if (sum >= 0)
            ans = i+1;
    for (int i = N - 1, sum = bonta[i]; i >= 0; sum += bonta[--i])
        if (sum >= 0 && N-i > ans)
            ans = N - i;
        
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
