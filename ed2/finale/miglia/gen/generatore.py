#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
from sortedcontainers import SortedSet as sortedset

usage="""Generatore di "miglia".

Parametri:
* X (massimo valore di K ammesso)
* T (tipo: 0-generico, 1-pesomax1, 2-gradomax2)
* S (seed)

Constraint:
* 2 <= X <= %d
* 0 <= T <= 2

""" % (MAXK)

def run(X, T):
    V = 1 if T==1 else MAXV
    K = X if (randint(0,2) == 0) else randint(2, X)
    N = MAXN-K+2 if (randint(0,2) == 0) else randint(2*K+2 if T==2 else 6, MAXN-K+2)
    M = 2*N-K if T==2 else MAXM-K+1
    M = M if (randint(0,2) == 0) else randint(N+K+2, M)
    N1 = randint((K+1)/2,N-(K+1)/2) if T==2 else randint(3,N-3)
    N2 = N-N1
    M1 = randint(max(0,M-K-2-2*N2),min(2*N1-2-K,M-K-2)) if T==2 else randint(N1,M-N-K-2+N1)
    M2 = M-M1-K-2
    V1 = randint(1,V)
    if T==2:
        assert(0 <= M1 <= 2*N1 - K - 2)
        assert(0 <= M2 <= 2*N2)
    deg = [0 for _ in xrange(N)]
    E = []
    # links tra parte 1 e 2
    E.append([randint(1,N1-1), randint(N1,N-1), 0])
    deg[E[-1][0]] += 1
    E.append((randint(N1,N-1), randint(0,N1-1), randint(0,V)))
    deg[E[-1][0]] += 1
    deg[0] += 1 # per via del ciclo esterno
    # K-ciclo
    lasti = newi = 0
    for i in xrange(K-1):
        while newi == lasti or (newi == 0 and i == K-2) or (deg[newi]==T==2):
            newi = randint(0,N1-1)
        E.append((lasti, newi, randint(0,randint(0,V1))))
        deg[E[-1][0]] += 1
        lasti = newi
    E.append((lasti, 0, randint(0,V1)))
    deg[E[-1][0]] += 1
    # archi in zona 1 e 2
    for xxx in [(M1,0,N1,0,V1), (M2,N1,N,V1,V)]:
        nodes = sortedset([i for i in xrange(xxx[1],xxx[2]) if deg[i]<2]) if T==2 else xrange(xxx[1],xxx[2])
        for i in xrange(xxx[0]):
            lasti = newi = choice(nodes)
            while newi == lasti:
                newi = randint(0,xxx[2]-1)
            E.append((lasti, newi, randint(0 if randint(0,1) else xxx[3],xxx[4])))
            deg[E[-1][0]] += 1
            if deg[E[-1][0]] == T == 2:
                nodes.discard(E[-1][0])
    # aggiusto peso E[0] e asserto
    maxv = V1
    for ed in E[1:]:
        if ed[0] == E[0][0]:
            maxv = min(maxv, ed[2])
    E[0][2] = randint(0,maxv)
    if T == 2:
        assert(all([deg[i] <= 2 for i in xrange(N)]))
    # inserisco ciclo fallace esterno
    E.append((0,N,V))
    for i in xrange(N,N+K-3):
        E.append((i,i+1,V))
    E.append((N+K-3,0,V))
    N += K-2
    M += K-1
    # shuffling
    shuf = range(1,N)
    shuffle(E)
    shuffle(shuf)
    shuf = [0] + shuf
    print K, N, M
    for ed in E:
        print shuf[ed[0]], shuf[ed[1]], ed[2]

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    X, T, S = map(int, argv[1:])

    assert (2 <= X <= MAXK)
    assert (0 <= T <= 2)
    seed(S)
    run(X, T)
