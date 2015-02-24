#include <stdio.h>
#include <assert.h>

#define MAXN 100000

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int osserva(int N, int H[]) {
    int risp = 0, l, r;
    for (int i=0; i<N; i++) {
        // calcolo quanto vedo sul grattacielo i
        for (l = max(i-1,0);   l > 0   and H[l] < H[i]; l--);
        for (r = min(i+1,N-1); r < N-1 and H[r] < H[i]; r++);
        risp = max(risp, r-l+1);
    }
    return risp;
}


int H[MAXN];

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
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", osserva(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
