#!/usr/bin/env python2

from limiti import *
from sys import argv, exit
from random import shuffle, seed, randint
from itertools import product

usage="""Generatore di "cubetti".

Parametri:
* N (numero di cubetti)
* S (seed)

Constraint:
* %d <= N <= %d
""" % (MINN, MAXN)


def run(N, S):
    print N
    relabel = range(1, N+1)
    shuffle(relabel)
    for i in xrange(N):
        print relabel[randint(0, N-2)],

if __name__ == "__main__":
    try:
        N, S = map(int, argv[1:])
    except ValueError:
        print usage
        exit(1)

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print """5
5 1 2 2 2""",
        exit(0)
    seed(S)

    assert (MINN <= N <= MAXN)

    run(N, S)
