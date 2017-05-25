#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int osserva(int N, int H[]) {
    // Mettete qui il codice della soluzione
	return 42;
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", osserva(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
