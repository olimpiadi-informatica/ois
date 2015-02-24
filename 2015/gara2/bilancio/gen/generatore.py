#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "bilancio".

Parametri:
* N (cifre totali)
* K (cifre da cancellare)
* S (seed)

Constraint:
* 1 <= K < N <= %d
""" % (MAXN)


def run(N, K):
    minc = randint(0,9)
    print N, K
    print randint(1,9),
    for i in xrange(1,N):
        print randint(minc,9),
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, K, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= K < N <= MAXN)
    seed(S)
    run(N, K)
