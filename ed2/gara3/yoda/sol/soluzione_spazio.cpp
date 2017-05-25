#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

#define MAXS 100010

void yodizza(char S[], char Y[]) {
  std::vector<std::string> v;
  std::string word;
  std::stringstream input(S), output;

  while (input >> word) {
    v.push_back(word);
  }

  std::reverse(v.begin(), v.end());

  for (auto w : v) {
    output << w << " ";
  }

  sprintf(Y, "%s", output.str().c_str());
}


char S[MAXS + 1], Y[MAXS + 1];

int main() {
    FILE *fr, *fw;

#ifndef USE_STDIN
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(NULL != fgets(S, MAXS + 1, fr));

    yodizza(S, Y);

    fprintf(fw, "%s\n", Y);
    fclose(fr);
    fclose(fw);
}
