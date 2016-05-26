#include <cstdio>
#include <cassert>
#include <vector>

#define MAXN 10000
#define MAXM 100000

int visto[MAXN];
std::vector<int> adj[MAXN];

void dfs(int u) {
  visto[u] = 1;
  for (int y: adj[u]) {
    if (!visto[y]) {
      dfs(y);
    }
  }
}

int raccogli(int N, int M, int monete[], int A[], int B[]) {
  for (int i=0; i<M; i++) {
    adj[A[i]].push_back(B[i]);
    adj[B[i]].push_back(A[i]);
  }
  dfs(0);
  int ans = 0;
  for (int i=0; i<N; i++) {
    ans += visto[i];
  }
  return ans;
}


int monete[MAXN];
int A[MAXM], B[MAXM];

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
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &monete[i]));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &A[i], &B[i]));

    fprintf(fw, "%d\n", raccogli(N, M, monete, A, B));
    fclose(fr);
    fclose(fw);
}
