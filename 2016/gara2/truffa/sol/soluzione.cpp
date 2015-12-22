#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

#define MAXN 100000

int sfangate(int N, int V[]) {
    sort(V, V+N);
    int sum = 0, s = 0;
    for (int i=0; i<N; i++) sum += V[i];
    for (s = 0; sum <= 0; s++) {
        sum -= 2*V[s];
    }
    return s;
}


int V[MAXN];

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
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}
