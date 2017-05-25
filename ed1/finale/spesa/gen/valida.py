#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


# 0            -> corretto
# altro numero -> non corretto
def run(f, st):
    N, M, K = map(int, f[0].split())
    assert( 1 <= N <= MAXN and 1 <= K <= N-2 and N-1 <= M <= MAXM)
    
    # supermercati
    supermercati = map(int, f[1].split())
    assert( 1 not in supermercati and N not in supermercati )
    assert( all([1 <= s <= N for s in supermercati]) )
    # - controlla non ci siano duplicati
    assert( len(supermercati) == len(set(supermercati)) )

    # Archi
    edges = [sorted(map(int, r.split())) for r in f[2:]]
    assert( len(edges) == M )
    assert( all([len(e) == 2 for e in edges]) )
    # - controlla che non ci siano duplicati
    assert( len(edges) == len(set(map(tuple,edges))) )
    # - controlla che non ci siano self-loops
    assert( filter(lambda x: x[0] == x[1], edges) == [] )
    # controlla che il grafo sia connesso
    adj = dict()
    for e in edges:
        if e[0] not in adj:
            adj[e[0]] = []
        if e[1] not in adj:
            adj[e[1]] = []
        adj[e[0]] += [e[1]]
        adj[e[1]] += [e[0]]
    queue = [1]
    marked = set([1])
    while queue:
        node = queue.pop(0)
        for a in adj[node]:
            if a not in marked:
                marked.add(a)
                queue.append(a)
    assert len(marked) == N

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
