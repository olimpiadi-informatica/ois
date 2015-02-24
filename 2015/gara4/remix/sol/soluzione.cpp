#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN (100000+1)

using namespace std;

void ripulisci(int N, char remix[], char testo[]) {
    string s(remix);
    string pah("PaH"), tunz("TuNZ");

    int j = -1, i = 0;
    while (i < N) {
        if (s.substr(i, 3) != pah && s.substr(i, 4) != tunz) {
            testo[++j] = s[i];
            ++i;
        } else {
            if (j != -1 && testo[j] != ' ')
                testo[++j] = ' ';
            if (s.substr(i, 3) == pah)
                i += 3;
            if (s.substr(i, 4) == tunz)
                i += 4;
        }
    }
    testo[++j] = 0;
}


char remix[MAXN], testo[MAXN];

int main() {
    FILE *fr, *fw;
    int N;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(remix == fgets(remix, N + 1, fr));

    ripulisci(N, remix, testo);
    fprintf(fw, "%s\n", testo);
    fclose(fr);
    fclose(fw);
    return 0;
}