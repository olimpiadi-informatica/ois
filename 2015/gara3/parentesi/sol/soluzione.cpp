#include <stdio.h>
#include <assert.h>

#define MAXN 102400

char Stack[MAXN];
int ns;

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
    for (int i=0; i<N; i++) {
        if (ns > 0 and match(Stack[ns-1], E[i])) {
            ns--;
        }
        else if (open(E[i])) {
            Stack[ns++] = E[i];
        }
        else return -1;
    }
    return -ns;
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
