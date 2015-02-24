#include <stdio.h>
#include <assert.h>

#define MAXN 102400

bool open(char c) {
    return (c == '<' or c == '(' or c == '[' or c == '{');
}

int type(char c) {
    if (c == '<' or c == '>') return 3;
    if (c == '(' or c == ')') return 2;
    if (c == '[' or c == ']') return 1;
    if (c == '{' or c == '}') return 0;
}

int C[4];

int controlla(int N, char E[]) {
    for (int i=0; i<N; i++) {
        if (open(E[i])) {
            C[type(E[i])]++;
            for (int j=type(E[i])+1; j<4; j++)
                if (C[j] > 0) return -1;
        }
        else {
            C[type(E[i])]--;
            for (int j=type(E[i])+1; j<4; j++)
                if (C[j] > 0) return -1;
        }
        if (C[type(E[i])] < 0) return -1;
    }
    return -(C[0]+C[1]+C[2]+C[3]);
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
