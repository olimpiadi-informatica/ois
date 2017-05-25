#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "duplicato".

Parametri:
* N (numero)
* MAXP (numero)
* S (seed)

Constraint:
* %d <= N <= %d
""" % (MINN, MAXN)


def run(N, MAXP):
    print N
    p = sample(xrange(1, MAXP), k = N)
    p += p[:N-1]
    shuffle(p)
    print ' '.join(map(str, p))

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, MAXP, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (MINN <= N <= MAXN)
    seed(S)
    run(N, MAXP)
