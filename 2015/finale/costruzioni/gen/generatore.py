#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "costruzioni".

Parametri:
* N (numero)
* K (numero)
* S (seed)

Constraint:
* 1 <= N <= K <= %d
""" % (MAXN)


def run(N, K):
    print N, K
    for i in xrange(N):
        print randint(1,MAXV),
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
    assert (1 <= N <= MAXN)
    assert (1 <= K <= N)
    seed(S)
    run(N, K)
