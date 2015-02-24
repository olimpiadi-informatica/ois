#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int degusta(int N, int *V) {
	return 42;
}


int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", degusta(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
