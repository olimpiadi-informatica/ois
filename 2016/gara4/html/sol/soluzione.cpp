#include <bits/stdc++.h>

int unescape(int N, char S[]) {
    std::vector<char> stack;
    for (int i = 0; i < N; i++) {
        stack.push_back(S[i]);
        size_t L = stack.size();
        if (L >= 5 && stack[L - 1] == ';' && stack[L - 2] == 'p' &&
                stack[L - 3] == 'm' && stack[L - 4] == 'a' &&
                stack[L - 5] == '&') {
            stack.pop_back(); stack.pop_back();
            stack.pop_back(); stack.pop_back();
        }
    }

    for (size_t i = 0; i < stack.size(); i++) {
        S[i] = stack[i];
    }

    return stack.size();
}


const int MAXN = 1000000;

char S[MAXN];

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
