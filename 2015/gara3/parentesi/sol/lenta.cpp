#include <stdio.h>
#include <assert.h>

#define MAXN 10240

char T[MAXN][MAXN];

bool match(char c, char d) {
    if (c == '<' and d == '>') return true;
    if (c == '(' and d == ')') return true;
    if (c == '[' and d == ']') return true;
    if (c == '{' and d == '}') return true;
    return false;
}

bool controlla_rec(int N, char E[], int st) {
    if (N == 0) return true;
    if (T[N][st] > 0) return T[N][st] == 1;
    bool ok = false;
    for (int i=1; i<N and not ok; i+=2)
        if (match(E[0], E[i])) {
            ok = controlla_rec(i-1, E+1, st+1) and controlla_rec(N-i-1, E+i+1, st+i+1);
        }
    T[N][st] = ok ? 1 : 2;
    return ok;
}

int controlla(int N, char E[]) {
    if (N % 2 == 1) return -1;
    return controlla_rec(N, E, 0) ? 0 : -1;
}


char E[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

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
    assert(fgets(E, MAXN + 5, fr) == E);
    E[N] = 0;
    
    if (controlla(N, E) < 0)
        fprintf(fw, "malformata\n");
    else
        fprintf(fw, "corretta\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
