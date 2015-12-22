#!/usr/bin/env pypy

from limiti import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "monete".

Parametri:
* N (numero di nodi del grafo)
* M (numero di archi del grafo)
* T (tipo)
* S (seed)

T = 0 significa normale
T = 1 significa tutte le piattaforme hanno esattamente 1 moneta
T = 2 significa normale ma con grafo connesso

Constraint:
* 1 <= N <= %d
* 0 <= M <= %d
* M <= N*(N-1)/2
""" % (MAXN, MAXM)

def run(N, M, T):
    g = ugraph(N)

    if T == 2:
        if M < N-1:
            raise Exception("M must be at least N-1")
        g.connect()
        g.addedges(M - (N - 1))
    else:
        g.addedges(M)

    g.shuffle()

    if T != 1:
        # With 80% probability returns [0,1000], with 20% probability returns 0
        weigth = lambda: randint(0, MAXmonete) if random() < 0.8 else 0
    else:
        weigth = lambda: 1

    print N, M
    print " ".join([str(weigth()) for i in range(N)])
    print g.printedges(True)

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, M, T, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (0 <= M <= MAXM)
    assert (M <= N*(N-1)/2)
    assert (T in (0, 1, 2))
    seed(S)
    run(N, M, T)
