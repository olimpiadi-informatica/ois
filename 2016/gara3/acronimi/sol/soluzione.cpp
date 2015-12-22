#include <cstdio>
#include <cassert>
#include <cstring>

#define MAXA 100
#define MAXS 100000
#define MOD 1000000007

int dp[MAXA][MAXS];
char A[MAXA + 1], S[MAXS + 1];
int K, N;

int f(int i, int j) {
  if (i == K)
    return 1;
  if (j == N)
    return 0;

  int &ret = dp[i][j];
  if (ret != -1)
    return ret;

  ret = f(i, j+1) % MOD;
  if (A[i] == S[j]) {
    ret += f(i+1, j+1);
    ret %= MOD;
  }

  return ret;
}

int acronimi(char A[], char S[]) {
  K = strlen(A);
  N = strlen(S);
  memset(dp, -1, sizeof dp);
  return f(0, 0);
}


int main() {
    FILE *fr, *fw;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%s", A));
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", acronimi(A, S));
    fclose(fr);
    fclose(fw);
}
