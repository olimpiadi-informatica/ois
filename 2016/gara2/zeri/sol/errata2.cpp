#include <cstdio>
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

char S[MAXN + 1];

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
    assert(1 == fscanf(fr, "%s", S));

    int num = 0;
    for (int i=0; S[i]; i++) {
        if (S[i] == 'x') {
            doit(num, 2);
            doit(num, 5);
            num = 0;
        } else {
            num = 10 * num + int(char(S[i]) - '0');
        }
    }
    doit(num, 2);
    doit(num, 5);

    fprintf(fw, "%d\n", ans[5]);
    fclose(fr);
    fclose(fw);
    return 0;
}
