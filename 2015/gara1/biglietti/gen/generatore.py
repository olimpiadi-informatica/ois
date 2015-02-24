#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
import string

usage="""Generatore di "interrogazioni".

Parametri:
* N (numero totale di domande)
* S (seed)

Constraint:
* 2 <= N <= %d
""" % (MAXN)

def run(N):
    M = randint(2, 3 * N)
    A = randint(1, MAXN / 100)
    if (random() > .7): # 30%
        B = randint(1, min(MAXN, M * A - 1))
    else:
        B = min(MAXN, A * M + 1)
    print N, M, A, B

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    seed(S)

    run(N)
