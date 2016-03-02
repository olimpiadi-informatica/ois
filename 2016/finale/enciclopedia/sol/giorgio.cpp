#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>

#define MAXN 10240
#define MAXC 30

using namespace std;

FILE *fr, *fw;

void volume(char* S) {
    fprintf(fw, "%s\n", S);
}

int lcp[MAXN];

void rilega(int N, int K, char* parole[]) {
    for (int i=0; i<K; i++) {
        parole[2*i] = parole[(N/K)*i];
        parole[2*i+1] = parole[(N/K)*(i+1)-1];
    }
    N = 2*K;
    lcp[0] = lcp[N] = 0;
    for (int i=1; i<N; i++)
        for (lcp[i]=0; parole[i-1][lcp[i]] == parole[i][lcp[i]]; lcp[i]++);
    for (int i=0; i<N; i++) {
        for (int j=0; j<=max(lcp[i],lcp[i+1]); j++) if (parole[i][j]) parole[i][j] += ('A'-'a');
        parole[i][max(lcp[i],lcp[i+1])+1] = 0;
    }
    for (int i=0; i<N; i+=2) {
        fprintf(fw, "%s-%s\n", parole[i], parole[i+1]);
    }
}

char* parole[MAXN];

int main() {
    int N, K, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++) {
        parole[i] = (char*) malloc(sizeof(char) * (MAXC + 1));
        assert(0 < fscanf(fr, "%s", parole[i]));
    }

    rilega(N, K, parole);

    //for(i=0; i<N; i++)
    //    free(parole[i]);

    fclose(fr);
    fclose(fw);
    return 0;
}
