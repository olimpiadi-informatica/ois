#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

#define MAXN 100000

int zeri(int N, char S[]) {
    unsigned long long tot = 1;
    int num = 0;
    for (int i=0; S[i]; i++) {
        if (S[i] == 'x') {
            tot *= num;
            num = 0;
        } else {
            num = 10 * num + S[i] - '0';
        }
    }
    tot *= num;

    // Converti in stringa
    sprintf(S, "%llu", tot);

    int ans = 0;
    for (int i = strlen(S) - 1; i >= 0; i--) {
        if (S[i] == '0')
            ans += 1;
        else
            break;
    }

    return ans;
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
