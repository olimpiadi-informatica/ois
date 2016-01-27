#include <bits/stdc++.h>

int unescape(int N, char S[]) {
    std::string s(S);
    std::regex e("&amp;");
    while (1) {
        std::string tmp = std::regex_replace(s, e, "&");
        if (tmp != s)
            s = tmp;
        else
            break;
    }
    strcpy(S, s.c_str());
    return s.length();
}


const int MAXN = 1000000;

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
