#include <stdio.h>
#include <assert.h>

#define MAXN 102400

int C[MAXN]; // C[i] e' dove finisce la catena benformata di parentesi che parte in E[i] (se E[i] e' parentesi aperta)

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
            i = st+1<N and open(E[st+1]) ? C[st+1]+1 : st+1;
            if (i<N and match(E[st], E[i]))
                C[st] = i+1<N and open(E[i+1]) ? C[i+1] : i;
            else return -1;
        }
    return C[0] == N-1 ? 0 : -1;
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
