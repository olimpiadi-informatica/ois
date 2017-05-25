#include <cstdio>

int N;
int count[100000];

int main() {
#ifndef USE_STDIN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a;
        scanf("%d", &a);
        count[a-1]++;
    }
    int ans = 0;
    for(int i=0; i<N; i++)
        ans += count[i]?count[i]-1:0;
    printf("%d\n", ans);
}
