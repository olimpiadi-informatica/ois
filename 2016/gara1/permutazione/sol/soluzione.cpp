#include <cstdio>
#include <cassert>

void permuta(int K, char* P) {
    int dir = -1;
    int left = 0, right = 0;

    for (int i=0; i<26; i++) {
        if (K > 0) {
            if (i % 2 == 0) {
                P[i] = 'A' + left;
                left++;
            } else {
                P[i] = 'Z' - right;
                right++;
            }
            K--;
        } else if (dir == 0) {
            P[i] = 'A' + left;
            left++;
        } else if (dir == 1) {
            P[i] = 'Z' - right;
            right++;
        } else {
            dir = (i % 2 == 0) ? 1 : 0;
            i--;
        }
    }
}


int main() {
    FILE *fr, *fw;
    int K;

#ifndef USE_STDIN
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
