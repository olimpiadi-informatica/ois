#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "crittografia".

Parametri:
* N (numero di cifre)
* C (cifra massima)
* S (seed)

Constraint:
* 1 <= N <= 9
* 1 <= C <= 9
"""


def run(N, C):
    N = [str(randint(1,C))] + [str(randint(0,C)) for i in xrange(N-1)]
    print ''.join(N)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, C, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= 9)
    assert (1 <= C <= 9)
    seed(S)
    run(N, C)
