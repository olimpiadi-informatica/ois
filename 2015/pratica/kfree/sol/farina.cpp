#include <iostream>
#include <cstdio>
using namespace std;

int N, K;
const int MAXVAL = 100000;
bool presente[MAXVAL + 1];

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int v; cin >> v;
		presente[v] = true;
	}

	int ans = 0;
	if (K > 1) {
		for (int i = 0; i <= MAXVAL; i++) {
			if (presente[i]) {
				ans++;
				if (i * K <= MAXVAL && presente[i * K])
					presente[i * K] = false; // cancella i * K dall'insieme
			}
		}
	}

	cout << ans << endl;

	return 0;
}



