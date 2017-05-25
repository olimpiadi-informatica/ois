#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

bool is_prime(int x) {
  for (int i=2; i*i<=x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int primi(char S[]) {
  std::vector<int> v;
  v.push_back(S[0] - '0');

  for (int i = 1; i < strlen(S); i++) {
    std::vector<int> vv;
    for (int x: v) {
      if (S[i] == '*') {
        for (int j=0; j<10; j++) {
          vv.push_back(x * 10 + j);
        }
      } else {
        vv.push_back(x * 10 + S[i] - '0');
      }
    }
    v = vv;
  }

  int ans = 0;
  for (int x: v) {
    if (is_prime(x)) {
      ans++;
    }
  }

  return ans;
}


#define MAXS 10
char S[MAXS];

int main() {
    FILE *fr, *fw;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", primi(S));
    fclose(fr);
    fclose(fw);
}
