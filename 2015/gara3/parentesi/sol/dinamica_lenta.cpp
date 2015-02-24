#include <stdio.h>
#include <assert.h>

#define MAXN 102400

int T[MAXN]; // T[i] e' dove si chiude la parentesi in E[i] (se E[i] e' parentesi aperta)

bool open(char c) {
    return (c == '<' or c == '(' or c == '[' or c == '{');
}

bool match(char c, char d) {
    if (c == '<' and d == '>') return true;
    if (c == '(' and d == ')') return true;
    if (c == '[' and d == ']') return true;
    if (c == '{' and d == '}') return true;
    return false;
}

int controlla(int N, char E[]) {
    int i;
    if (N % 2 == 1) return -1;
    for (int st=N-1; st>=0; st--)
        if (open(E[st])) {
            for (i=st+1; i<N and open(E[i]); i=T[i]+1);
            if (i<N and match(E[st], E[i])) T[st] = i;
            else return -1;
        }
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
