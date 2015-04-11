#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>

#define MAXM 100000

int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
	std::vector<std::unordered_set<int>> adj(N);

	for (int i = 0; i < M; ++i) {
        int u = conoscenzeA[i];
        int v = conoscenzeB[i];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    int nodi_rimossi = 0;
    // Cerchiamo tutti i nodi isolati
    for (int i = 0; i < N; ++i)
    	if (adj[i].empty())
    		++nodi_rimossi;

	// Cerchiamo tutte le foglie del grafo iniziale
    std::queue<int> foglie;
    for (int i = 0; i < N; ++i)
    	if (adj[i].size() == 1)
    		foglie.push(i);

    while (!foglie.empty()) {
    	int u = foglie.front();
    	foglie.pop();

    	// Rimuovi tutti gli archi da u ai vicini
    	for (const auto& v: adj[u]) {
    		adj[v].erase(u);

    		// Controllo se ho creato una nuova foglia
    		if (adj[v].size() == 1)
    			foglie.push(v);
    	}
    	adj[u].clear();

    	++nodi_rimossi;
    }

    return N - nodi_rimossi;
}

int conoscenzeA[MAXM], conoscenzeB[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &conoscenzeA[i], &conoscenzeB[i]));

    fprintf(fw, "%d\n", invita(N, M, conoscenzeA, conoscenzeB));
    fclose(fr);
    fclose(fw);
    return 0;
}
