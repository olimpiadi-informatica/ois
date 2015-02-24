#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int gioca(int X, int Y, int MX, int MY, int N, int *RX, int *RY, int *PX, int *PY) {
	return 42;
}


int RX[MAXN], RY[MAXN], PX[MAXN], PY[MAXN];

int main() {
    FILE *fr, *fw;
    int X, Y, MX, MY, N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(5 == fscanf(fr, "%d%d%d%d%d\n", &X, &Y, &MX, &MY, &N));
    for(i=0; i<N; i++)
        assert(4 == fscanf(fr, "%d%d%d%d", &RX[i], &RY[i], &PX[i], &PY[i]));

    fprintf(fw, "%d\n", gioca(X, Y, MX, MY, N, RX, RY, PX, PY));
    fclose(fr);
    fclose(fw);
    return 0;
}
