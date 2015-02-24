#include <cstdio>

int N, K;
bool usable[100001];

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        usable[a] = true;
    }
    int excluded = 0;
    for(int i=1; i<100001; i++) {
        if(!usable[i]) continue;
        if(K*i > 100000) continue;
        if(!usable[K*i]) continue;
        usable[K*i] = false;
        excluded++;
    }
    printf("%d\n", N - excluded);
}
