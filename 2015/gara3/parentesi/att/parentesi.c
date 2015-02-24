#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int controlla(int N, char E[]) {
    // Mettete qui il codice della soluzione
    return -1;
}


char E[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
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
