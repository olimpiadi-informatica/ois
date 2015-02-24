#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "taxi".

Parametri:
* N (lunghezza percorso)
* C (costo massimo)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= C <= %d
""" % (MAXN, MAXC)


def run(N, C):
    print N
    for i in xrange(N):
        print randint(1,C),
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, C, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= C <= MAXC)
    seed(S)
    run(N, C)
