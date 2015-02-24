#!/usr/bin/env pypy

from limiti import *
from varie import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "limiti".

Parametri:
* N (numero di nodi del grafo)
* M (numero di archi del grafo)
* V (massimo peso del grafo)
* E (esponente minimo)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= M <= %d
* M <= N*(N-1)
* 1 <= V <= %d
* 0 <= E <= N-2, V-1, (M-1)/2
""" % (MAXN, MAXM, MAXV)


def run(N, M, V, E):
    INC = sample(xrange(1,V+1),E+1)
    INC.sort()
    def wh(e):
        if e[0] < e[1] < E+2 and e[1]-e[0] < 3:
            return INC[e[0]]
        else:
            return randint(1,V)
    g = dgraph(N, w=wh)
    for i in xrange(E):
        g += [i, i+1]
        g += [i, i+2]
    g += [E, E+1]
    g.addedges(M-2*E-1)
    g.shuffle()
    print N, M
    print g.printedges(True)

if __name__ == "__main__":
    if len(argv) != 6:
        print usage
        exit(1)

    N, M, V, E, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (2 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    assert (M <= N*(N-1))
    assert (1 <= V <= MAXV)
    assert (0 <= E <= N-2)
    assert (E <= V-1)
    assert (E <= (M-1)/2)
    seed(S)
    run(N, M, V, E)
