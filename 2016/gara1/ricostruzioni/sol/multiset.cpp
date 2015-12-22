#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <set>

#define MAXN 100000

using namespace std;

multiset<int> Heights;

int spiana(int N, int K, int A[]) {
    for (int i=0; i<K; i++) {
        Heights.insert(A[i]);
    }
    int sol = (*Heights.rbegin() - *Heights.begin());

    for (int i=K; i<N; i++) {
        Heights.erase(Heights.find(A[i-K]));
        Heights.insert(A[i]);
        sol = min(sol, *Heights.rbegin() - *Heights.begin());
    }
    return sol;
}


int A[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &A[i]));

    fprintf(fw, "%d\n", spiana(N, K, A));
    fclose(fr);
    fclose(fw);
    return 0;
}
