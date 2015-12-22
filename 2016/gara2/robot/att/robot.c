#include <stdio.h>
#include <assert.h>

#define MAXN 512

typedef char matrix[MAXN][MAXN];

int osserva(int N, int M, matrix T) {
    // Mettete qui il codice della soluzione
    if (T[0][0] == 'X')
        return -1;
    return 42;
}


int main() {
    FILE *fr, *fw;
    int N, M, i;
    matrix T;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%s", T[i]));
    fprintf(fw, "%d\n", osserva(N, M, T));
    fclose(fr);
    fclose(fw);
    return 0;
}
