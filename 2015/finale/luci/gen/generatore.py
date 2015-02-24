#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "luci".

Parametri:
* N (numero)
* T (se K va ristretto a 100)
* S (seed)

Constraint:
* 1 <= N <= %d
* 0 <= T <= 1
""" % (MAXN)


def run(N, T):
    print N, randint(1, N), randint(1, MAXK) if T == 0 else randint(1, 100)
    
if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, T, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (0 <= T <= 1)
    seed(S)
    run(N, T)
