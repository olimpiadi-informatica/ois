#include <stdio.h>
#include <assert.h>

#define MAXN 10000

void aggiusta(int N, char s[]) {
	for (int i = 0; i < N; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z')
            s[i] = c - 'a' + 'A';
        else if (c >= 'A' && c <= 'Z')
            s[i] = c - 'A' + 'a';
    }
}

char s[MAXN + 5];

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

    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(s, MAXN + 5, fr) == s);
    s[N] = 0;

    aggiusta(N, s);
    fprintf(fw, "%s\n", s);
    fclose(fr);
    fclose(fw);
    return 0;
}
