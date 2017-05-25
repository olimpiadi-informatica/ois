#include <stdio.h>
#include <assert.h>

#define MAXN 1000000
#define MAXM 100000

typedef struct {
    int x, y;
} point;

point passeggia(int N, int M, char P[], int S[], int E[]) {
    // Mettete qui il codice della soluzione
    point p;
    p.x = 42;
    p.y = 42;
    return p;
}


char P[MAXN+2];
int S[MAXM], E[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d\n", &N, &M));
    assert(1 == fscanf(fr, "%s", P));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d %d", &S[i], &E[i]));

    point p = passeggia(N, M, P, S, E);
    fprintf(fw, "%d %d\n", p.x, p.y);
    fclose(fr);
    fclose(fw);
    return 0;
}
