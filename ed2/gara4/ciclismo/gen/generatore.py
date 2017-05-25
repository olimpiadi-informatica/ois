#!/usr/bin/env pypy

from limiti import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "ciclismo".

Parametri:
* N (numero di nodi del grafo)
* M (numero di archi del grafo)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= M <= %d
* M <= N*(N-1)/2
""" % (MAXN, MAXM)

def run(N, M):
    g = ugraph(N, type='tree')
    g.addedges(M-N+1)
    g.shuffle()
    print N, M
    for i in sample(xrange(MAXH+1),N):
        print i,
    print
    print g.printedges(True)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    assert (M <= N*(N-1)/2)
    seed(S)
    run(N, M)
