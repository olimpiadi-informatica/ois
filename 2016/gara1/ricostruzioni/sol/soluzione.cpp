#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct maxQueue {
    int Values[MAXN], Count[MAXN];
    int begin, end;
    maxQueue() : begin(0), end(0) {};
    int max() {
        return Values[begin];
    }
    void pop() {
        Count[begin]--;
        if (Count[begin] == 0) begin++;
    }
    int push(int x) {
        int c = 1;
        while (end > begin and Values[end-1] <= x) {
            c += Count[end-1];
            end--;
        }
        Values[end] = x;
        Count[end] = c;
        end++;
    }
};

maxQueue minQ, maxQ;

int spiana(int N, int K, int A[]) {
    for (int i=0; i<K; i++) {
        maxQ.push(A[i]);
        minQ.push(-A[i]);
    }
    int sol = maxQ.max() + minQ.max();
    for (int i=K; i<N; i++) {
        maxQ.pop();
        minQ.pop();
        maxQ.push(A[i]);
        minQ.push(-A[i]);
        sol = min(sol, maxQ.max() + minQ.max());
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
