#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "pianostudi".

Parametri:
* N (numero di corsi)
* T (max tempo)
* U (tutti uguali? 0/1)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= T <= %d
""" % (MAXN, MAXT)


def run(N, T, U):
    print N
    if not U:
        crediti = [randint(1, MAXC) for i in xrange(N)]
    else:
        c = randint(1, MAXC)
        crediti = [c] * N

    for i in xrange(N):
        da = randint(1,T)
        a = randint(1,T)
        if a < da:
            a, da = da, a
        print da, a, crediti[i]

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, T, U, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= T <= MAXT)
    seed(S)
    run(N, T, U)
