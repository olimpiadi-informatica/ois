#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
import graph

usage="""Generatore di "spesa".

Parametri:
* N (numero di nodi)
* M (numero di archi) -- se -1 usa random
* K (numero di supermercati)
* S (seed)

Constraint:
* 1 <= K <= N <= %d
* 1 <= M <= %d
""" % (MAXN, MAXM)


def run(N, M, K):
    if M != -1:
        print N, M, K
        for x in sample(xrange(2, N), K):
            print x,
        print
        G = graph.ugraph(N)
        G.connect()
        G.addedges(M - N + 1)
        print G.printedges()
    else:
        run(N, randint(N-1, min(N*(N-1)/2, MAXM)), K)

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, M, K, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN) and (1 <= K <= N) and ((N-1 <= M <= MAXM) or M == -1)
    seed(S)
    run(N, M, K)
