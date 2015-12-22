#include <cstdio>
#include <cassert>
#include <cstring>

#define MAXA 100
#define MAXS 100000

int acronimi(char A[], char S[]) {
  int K = strlen(A);
  int N = strlen(S);

  int ans = 0;

  for (int i0=0; i0 < N; i0++) if (S[i0] == A[0]) {
    if (K == 1) {
      ans++; continue;
    }
    for (int i1=i0+1; i1 < N; i1++) if (S[i1] == A[1]) {
      if (K == 2) {
        ans++; continue;
      }
      for (int i2=i1+1; i2 < N; i2++) if (S[i2] == A[2]) {
        if (K == 3) {
          ans++; continue;
        }
        for (int i3=i2+1; i3 < N; i3++) if (S[i3] == A[3]) {
          if (K == 4) {
            ans++; continue;
          }
          for (int i4=i3+1; i4 < N; i4++) if (S[i4] == A[4]) {
            ans++;
          }
        }
      }
    }
  }

  return ans;
}


char A[MAXA + 1], S[MAXS + 1];

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
