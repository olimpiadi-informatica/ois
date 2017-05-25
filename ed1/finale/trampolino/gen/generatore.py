#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "trampolino".

Parametri:
* N (numero)
* J (max jump)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N, J):
    print N
    for i in xrange(N):
        print randint(1,J),
    print
    

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, J, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN and 1 <= J)
    seed(S)
    run(N, J)
