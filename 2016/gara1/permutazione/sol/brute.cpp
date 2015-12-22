#include <cstdio>
#include <cassert>
#include <algorithm>
#include <set>

int conta(char* P) {
    std::set<int> diff;
    for (int i=1; i<26; i++) {
        diff.insert(abs(P[i] - P[i-1]));
    }
    return diff.size();
}

void permuta(int K, char* P) {
    for (int i=0; i<26; i++) {
        P[i] = 'A' + i;
    }

    while (conta(P) != K) {
        std::next_permutation(P, P+26);
    }
}


int main() {
    FILE *fr, *fw;
    int K;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%d", &K));

    char P[27];
    permuta(K, P);
    P[26] = '\0';

    fprintf(fw, "%s\n", P);
    fclose(fr);
    fclose(fw);
    return 0;
}
