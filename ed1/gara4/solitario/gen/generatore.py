#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "solitario".

Parametri:
* N (numero)
* M (numero)
* S (seed)

Constraint:
* 1 <= N, M <= %d
""" % (MAXN)


def run(N, M):
    print N, M

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= M <= MAXN)
    assert (N*M <= MAXNM)
    seed(S)
    run(N, M)
