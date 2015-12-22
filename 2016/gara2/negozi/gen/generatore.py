#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "negozi".

Parametri:
* N (numero di negozi)
* Q (numero di query)
* T (numero di tipi di negozio possibili)
* D (percentuale di "diversificazione" dei tipi)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= Q <= %d
* 1 <= T <= %d
* 0.0 <= D <= 1.0
""" % (MAXN, MAXQ, MAXT)


def run(N, Q, T, D):
    print N, Q

    # Tipi usabili
    types = sample(xrange(T), int(D * N))

    # Assegna un tipo a ciascun negozio
    shops = [choice(types) for s in xrange(N)]
    print " ".join(map(str, shops))

    # Delete unused types
    types = list(set(shops))

    for i in xrange(Q):
        # Query di cose a caso
        print choice(xrange(N)), choice(types)

if __name__ == "__main__":
    if len(argv) != 6:
        print usage
        exit(1)

    D = float(argv[4])
    N, Q, T, S = map(int, argv[1:4] + argv[5:])

    seed(S)
    run(N, Q, T, D)
