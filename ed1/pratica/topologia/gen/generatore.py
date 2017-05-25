#!/usr/bin/env python2

from limiti import *
from varie import *
from sys import argv, exit
from random import shuffle, seed, randint, choice, sample
from itertools import product

usage="""Generatore di "kfree".

Parametri:
* N (numero di nodi del grafo)
* M (numero di archi del grafo)
* K (minimo numero di componenti connesse del grafo)
* S (seed)

oppure

Parametri (grafo connesso):
* N (numero di nodi del grafo connesso)
* T (risultato: 0 = linear, 1 = ring, 2 = star, 3 = unknown)
* S (seed)

Constraint:
* %d <= N <= %d
* %d <= M <= %d
* M <= N*(N-1)/2
* 1 <= K <= N
""" % (MINN, MAXN, MINM, MAXM)

def path(base, size, edges):
    edg = []
    for i in xrange(base, base+size-1):
        edg.append((i, i+1))
    return edg

def ring(base, size, edges):
    edg = []
    for i in xrange(base, base+size-1):
        edg.append((i, i+1))
    edg.append((base+size-1, base))
    return edg

def star(base, size, edges):
    edg = []
    for i in xrange(base, base+size-1):
        edg.append((base, i+1))
    return edg

def random(base, size, edges):
    edg = set()
    while len(edg) < edges:
        a = randint(base+1, base+size-1)
        b = randint(base, a-1)
        edg.add((a, b))
    return list(edg)

def run1(N, M, K):
    # check assumptions
    assert (MINN <= N <= MAXN)
    assert (MINM <= M <= MAXM)
    assert (1 <= K <= N)

    print N, M
    g_type = [path, ring, star, random]
    g_size = [lambda x: x-1, lambda x: x, lambda x: x-1, lambda x: 0]
    count_ok = False
    while not count_ok:
        bases = range(1, N-1)
        shuffle(bases)
        bases = [0] + bases[:K-1] + [N]
        bases.sort()
        sizes = [bases[i+1] - bases[i] for i in xrange(K)]
        types = [randint(0, 3) for i in xrange(K)]
        if sum([types[i] == 1 and sizes[i] < 3 for i in xrange(K)]):
            continue
        n_edges = [g_size[types[i]](sizes[i]) for i in xrange(K)]
        used_edges = sum(n_edges)
        extra_edges = M - used_edges
        rnd_comp = [i for i in xrange(K) if types[i] == 3 and sizes[i] > 1]
        if extra_edges < 0:
            continue
        while(extra_edges > 0 and len(rnd_comp) > 0):
            v = choice(rnd_comp)
            n_edges[v] += 1
            if n_edges[v] == (sizes[v] * (sizes[v]-1))/2:
                rnd_comp.remove(v)
            extra_edges -= 1
        if extra_edges > 0:
            continue
        count_ok = True
    edg = []
    for i in xrange(K):
        edg += g_type[types[i]](bases[i], sizes[i], n_edges[i])
    shuffle(edg)
    labels = range(1, N+1)
    shuffle(labels)
    for e in edg:
        print labels[e[0]], labels[e[1]]

def run2(N, T):
    # check assumptions
    assert (MINN <= N <= MAXN)
    assert T in range(4)

    edg = []
    if T == 0:     # linear
        for i in xrange(N-1):
            edg.append((i, i+1))
    elif T == 1:   # ring
        for i in xrange(N):
            edg.append((i, (i+1) % N))
    elif T == 2:   # star
        for i in xrange(N-1):
            edg.append((0, i+1))
    else:          # unknown
        # make sure that it always stays connected
        tree = [0]
        for i in xrange(N-1):
            # pick a node and append (i+1) to it
            edg.append((choice(tree), i+1))
            # now (i+1) is part of the tree
            tree.append(i+1)
        # add some edges (but not too many, because it's too easy if
        # M > N holds too frequently), thus, M will be either:
        # (N-1), (N), (N+1)
        additional_edges = randint(0, 2)
        for i in xrange(additional_edges):
            while True:
                new_edge = tuple(sample(tree, 2))
                if (new_edge not in edg) and (new_edge[::-1] not in edg):
                    break
            edg.append(new_edge)
    shuffle(edg)
    labels = range(1, N+1)
    shuffle(labels)
    print N, len(edg)
    for e in edg:
        print labels[e[0]], labels[e[1]]

if __name__ == "__main__":
    try:
        N, M, K, S = map(int, argv[1:])
    except ValueError:
        try:
            N, T, S = map(int, argv[1:])
        except ValueError:
            print usage
            exit(1)

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    seed(S)

    try:
        run1(N, M, K)
    except NameError:
        run2(N, T)
