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
* K (numero di domande da scegliere)
* S (seed)

Constraint:
* 2 <= N <= %d
* 2 <= K <= N
""" % (MAXN)

def run(K, N):
    print N, K
    for i in xrange(N):
        print randint(1, MAXD),

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, K, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (2 <= N <= MAXN)
    assert (2 <= K <= N)
    seed(S)

    run(K, N)
