#include <stdio.h>
#include <assert.h>

#define MAXN 102400

bool open(char c) {
    return (c == '<' or c == '(' or c == '[' or c == '{');
}

int controlla(int N, char E[]) {
    int count = 0;

    for (int i=0; i<N; i++) {
        if (open(E[i])) count++;
        else count--;
        if (count < 0) return -1;
    }
    return -count;
}


char E[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

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
