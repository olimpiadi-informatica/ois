#include <iostream>
#include <cstdio>

bool seen[100001];

using namespace std;

int main(){
#ifndef USE_STDIN
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int ans = 0;
	int N;
	
	cin >> N;
	
	for (int i=0; i<N; i++){
		int v;
		cin >> v;
		seen[v] = 1;
	}
	
	for (int i=1; i<=N; i++){
		if (!seen[i]) ans++;
	}
	
	cout << ans << "\n";
	return 0;
}