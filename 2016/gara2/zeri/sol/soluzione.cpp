#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

#define MAXN 100000

int ans[10] = {0};

void doit(int x, int d) {
    while (x % d == 0) {
        x /= d;
        ans[d] += 1;
    }
}

int zeri(int N, char S[]) {
    int num = 0;
    for (int i=0; S[i]; i++) {
        if (S[i] == 'x') {
            doit(num, 2);
            doit(num, 5);
            num = 0;
        } else {
            num = 10 * num + S[i] - '0';
        }
    }
    doit(num, 2);
    doit(num, 5);

    return std::min(ans[2], ans[5]);
}

char S[MAXN + 1];

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
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", zeri(strlen(S), S));
    fclose(fr);
    fclose(fw);
    return 0;
}
