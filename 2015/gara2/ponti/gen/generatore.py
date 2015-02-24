#!/usr/bin/env pypy

from limiti import *
from varie import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "ponti".

Parametri:
* N (numero di nodi del grafo)
* M (numero di archi del grafo)
* S (seed)

Constraint:
* 2 <= N <= %d
* 0 <= M <= %d
* M <= N*(N-1)/2
""" % (MAXN, MAXM)

def run(N, M):
    g = ugraph(N)
    g.addedges(M)
    g.shuffle()
    print N, M
    print g.printedges(True)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (2 <= N <= MAXN)
    assert (0 <= M <= MAXM)
    assert (M <= N*(N-1)/2)
    seed(S)
    run(N, M)
