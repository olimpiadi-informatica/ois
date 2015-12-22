#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

struct Trie {
  struct Node {
    Node* ptr[10] = {nullptr};
  } *root = new Node();

  void actual_add(Node* node, const char* s, unsigned rem) {
    if (rem == 0) {
      return;
    }

    if (node->ptr[s[0] - '0'] == nullptr) {
      node->ptr[s[0] - '0'] = new Node();
    }

    actual_add(node->ptr[s[0] - '0'], s + 1, rem - 1);
  }

  void add(std::string s) {
    actual_add(root, s.c_str(), s.length());
  }

  int visit_mask(Node* node, const char* s, unsigned rem) {
    if (node == nullptr) {
      return 0;
    }

    if (rem == 0) {
      return 1;
    }

    if (s[0] == '*') {
      int ans = 0;
      for (int i=0; i<10; i++) {
        ans += visit_mask(node->ptr[i], s + 1, rem - 1);
      }
      return ans;
    }

    if (node->ptr[s[0] - '0'] == nullptr) {
      return 0;
    } else {
      return visit_mask(node->ptr[s[0] - '0'], s + 1, rem - 1);
    }
  }
} trie;

#define MAXN 100000000
bool composite[MAXN];

int primi(char S[]) {
  int M = 1;
  for (unsigned i=0; i<strlen(S); i++) {
    M *= 10;
  }

  for (int i=2; i*i<=M; i++) {
    if (!composite[i]) {
      for (int j=i+i; j<M; j+=i) {
        composite[j] = 1;
      }
    }
  }

  for (int i=2; i<M; i++) {
    if (!composite[i]) {
      trie.add(std::to_string(i));
    }
  }

  return trie.visit_mask(trie.root, S, strlen(S));
}


#define MAXS 10
char S[MAXS];

int main() {
    FILE *fr, *fw;

#ifdef EVAL
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
