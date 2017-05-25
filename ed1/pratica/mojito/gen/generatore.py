#!/usr/bin/env python2

from limiti import *
from varie import *
from sys import argv, exit
from random import sample, seed

usage="""Generatore di "mojito".

Parametri:
* X (numero di righe)
* Y (numero di colonne)
* N (numero di ragazzi)
* S (seed)

Constraint:
* 1 <= X, Y <= %d
* 1 <= N <= %d
""" % (MAXX, MAXN)


def single_cell():
    c = cells.pop()
    return "%d %d" % (c/Y+1,c%Y+1)

def run(X, Y, N):
    print X, Y
    print single_cell()
    print N
    for i in xrange(N):
        print single_cell(), single_cell()

if __name__ == "__main__":
    try:
        X, Y, N, S = map(int, argv[1:])
    except ValueError:
        print usage
        exit(1)

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    seed(S)

    assert (1 <= X <= MAXX)
    assert (1 <= Y <= MAXX)
    assert (1 <= N <= MAXN)

    # genera tutte le celle possibili
    cells = sample(xrange(X*Y), 2*N+1)

    run(X, Y, N)
