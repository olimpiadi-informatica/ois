#include <stdio.h>
#include <assert.h>

#define MAXN 1000000
#define MAXM 100000

struct point {
    int x, y;
};

int xoffs[MAXN+1];
int yoffs[MAXN+1];
int doffs[MAXN+1];
int booms[MAXN+1];

point passeggia(int N, int M, char P[], int S[], int E[]) {
    xoffs[0] = 0;
    yoffs[0] = 0;
    doffs[0] = 0;
    booms[0] = 0;
    for (int i=0; i<N; i++) {
        doffs[i+1] = (doffs[i] + (P[i] == 'L') - (P[i] == 'R')+4)%4;
        xoffs[i+1] = xoffs[i];
        yoffs[i+1] = yoffs[i];
        if (P[i] == 'F') {
            if (doffs[i] % 2 == 0) xoffs[i+1] += 1 - doffs[i];
            else yoffs[i+1] += 2 - doffs[i];
        }
        if (P[i] == 'B') {
            if (doffs[i] % 2 == 0) xoffs[i+1] -= 1 - doffs[i];
            else yoffs[i+1] -= 2 - doffs[i];
        }
        booms[i+1] = booms[i] + (P[i] == 'X');
    }
    point p;
    p.x = 0;
    p.y = 0;
    int dir = 0;
    for (int i=0; i<M; i++) {
        if (booms[E[i]+1]-booms[S[i]] > 0)  // boom!!
            for (int j=S[i]; j<=E[i]; j++) if (P[j] == 'X') {
                E[i] = j-1;
                M = i+1;
            }
        switch ((dir-doffs[S[i]]+4)%4) {
            case 0:
                p.x += xoffs[E[i]+1]-xoffs[S[i]];
                p.y += yoffs[E[i]+1]-yoffs[S[i]];
                break;
            case 1:
                p.x -= yoffs[E[i]+1]-yoffs[S[i]];
                p.y += xoffs[E[i]+1]-xoffs[S[i]];
                break;
            case 2:
                p.x -= xoffs[E[i]+1]-xoffs[S[i]];
                p.y -= yoffs[E[i]+1]-yoffs[S[i]];
                break;
            case 3:
                p.x += yoffs[E[i]+1]-yoffs[S[i]];
                p.y -= xoffs[E[i]+1]-xoffs[S[i]];
                break;
        }
        dir = (dir + doffs[E[i]+1]-doffs[S[i]]+4)%4;
    }
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
