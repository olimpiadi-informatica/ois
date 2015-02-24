#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "grattacieli".

Parametri:
* N (numero di grattacieli)
* H (altezza massima, se < 0 vengono stampati in ordine crescente)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= |H| <= %d
""" % (MAXN, MAXH)


def run(N, H):
    l = [randint(1,abs(H)) for i in xrange(N)]
    if H < 0:
        l.sort()
    print N
    for i in l:
        print i,
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, H, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= abs(H) <= MAXH)
    seed(S)
    run(N, H)
