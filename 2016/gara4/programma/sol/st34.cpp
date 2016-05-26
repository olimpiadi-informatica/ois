#include <stdio.h>
#include <assert.h>

#define MAXN 1000000
#define MAXM 100000

struct point {
    int x, y;
};

int  offs[MAXN+1];
int  boom[MAXN+1];

point passeggia(int N, int M, char P[], int S[], int E[]) {
    offs[0] = 0;
    boom[0] = 0;
    for (int i=0; i<N; i++) {
        offs[i+1] = offs[i] + (P[i] == 'F') - (P[i] == 'B');
        boom[i+1] = boom[i] + (P[i] == 'X');
    }
    int xpos = 0;
    for (int i=0; i<M; i++) {
        if (boom[E[i]+1]-boom[S[i]] > 0) {  // boom!!
            for (int j=S[i]; j<=E[i] and P[j] != 'X'; j++)
                xpos += (P[j] == 'F') - (P[j] == 'B');
            i = M;
        }
        else xpos += offs[E[i]+1]-offs[S[i]];
    }
    point p;
    p.x = xpos;
    p.y = 0;
    return p;
}


char P[MAXN+2];
int S[MAXM], E[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
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
