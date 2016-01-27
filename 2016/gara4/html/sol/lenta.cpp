#include <bits/stdc++.h>

const int MAXN = 1000000;
const char* LOOKFOR = "&amp;";
const size_t LOOKLEN = strlen(LOOKFOR);

char tmp[MAXN + 1];

int unescape(int N, char S[]) {
    bool go = true;

    while (go) {
        go = false;

        char* pos = S;
        char* newpos;
        int i = 0;
        while (1) {
            newpos = strstr(pos, LOOKFOR);
            if (newpos == NULL) {
                newpos = S + N;
            }

            memcpy(tmp + i, pos, newpos - pos);
            i += newpos - pos;

            if (newpos < S + N) {
                tmp[i++] = '&';
                pos = newpos + LOOKLEN;
                go = true;
            } else {
                break;
            }
        }

        strcpy(S, tmp);
    }

    return strlen(S);
}


char S[MAXN];

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
    assert(1 == fscanf(fr, "%d\n", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%c", &S[i]));

    N = unescape(N, S);
    fprintf(fw, "%d\n", N);
    for(i=0; i<N; i++)
        fprintf(fw, "%c", S[i]);
    fclose(fr);
    fclose(fw);
    return 0;
}
