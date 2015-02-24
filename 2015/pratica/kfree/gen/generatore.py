#!/usr/bin/env python2

from limiti import *
from sys import argv, exit
from random import shuffle, seed, randint
from itertools import product

usage="""Generatore di "kfree".

Parametri:
* N (numero di elementi dell'insieme)
* K
* S (seed)

Constraint:
* %d <= N <= %d
* %d <= K <= %d
""" % (MINN, MAXN, MINK, MAXK)


def run(N, K, S):
    print N, K
    ints = range(1, min(100001, 2*N))
    shuffle(ints)
    print " ".join(map(str, ints[:N]))

if __name__ == "__main__":
    try:
        N, K, S = map(int, argv[1:])
    except ValueError:
        print usage
        exit(1)

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print """6 2
2 3 6 5 4 10""",
        exit(0)
    seed(S)

    assert (MINN <= N <= MAXN)
    assert (MINK <= K <= MAXK)

    run(N, K, S)
