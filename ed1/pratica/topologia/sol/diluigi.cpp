#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

const int MAXN = 100000;

int         N;               // number of vertices
int         M;               // number of edges
vector<int> adj[MAXN];       // adj[x] = x's adjacency list
bool        visited[MAXN];   // visited[x] = true iff x has been visited
int         deg[MAXN];       // deg[x] = number of edges incident to x
vector<int> subnet;          // list of a subnet's vertices
int         subnet_edges;    // number of edges in a subnet
int         linear;          // number of linear topologies
int         ring;            // number of ring topologies
int         star;            // number of star topologies

void dfs(const int u) {
  visited[u] = true;
  subnet.push_back(u);
  for (vector<int>::const_iterator it=adj[u].begin(); it!=adj[u].end(); it++) {
    int v = *it;
    subnet_edges += 1;
    if (!visited[v]) {
      dfs(v);
    }
  }
}

void check_subnet() {
  assert(subnet_edges % 2 == 0);
  subnet_edges /= 2; // each edge has been counted twice

  int subnet_vertices = subnet.size();

  if (subnet_vertices < 2 || subnet_edges > subnet_vertices) {
    return; // unknown topology
  }

  int ones = 0; // number of vertices x such that deg[x] = 1
  int twos = 0; // number of vertices x such that deg[x] = 2
  int maxd = 0; // maximum deg[x]

  for (vector<int>::const_iterator it=subnet.begin(); it!=subnet.end(); it++) {
    int u = *it;
    ones += (deg[u] == 1);
    twos += (deg[u] == 2);
    maxd = max(maxd, deg[u]);
  }

  if (subnet_edges == subnet_vertices - 1) {
    if (ones == 2 && twos == subnet_vertices - 2) {
      linear += 1; // linear topology
    } else if (maxd == subnet_vertices - 1) {
      star += 1; // star topology
    }
  } else {
    assert(subnet_edges == subnet_vertices);
    if (ones == 0 && maxd == 2) {
      ring += 1; // ring topology
    }
  }
}

int main() {
#ifndef USE_STDIN
  ifstream fin ("input.txt");
  ofstream fout("output.txt");
#else
  istream &fin (cin);
  ostream &fout(cout);
#endif

  fin >> N >> M;

  for (int i=0; i<M; i++) {
    int u, v;
    fin >> u >> v;
    assert(1 <= u && u <= N);
    assert(1 <= v && v <= N);
    u -= 1;
    v -= 1;
    deg[u] += 1;
    deg[v] += 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int u=0; u<N; u++) {
    if (!visited[u]) {
      dfs(u);
      check_subnet();
      subnet.clear();
      subnet_edges = 0;
    }
  }

  fout << linear << " " << ring << " " << star << endl;
}
