#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
import string
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "yoda".

Parametri:
* N (lunghezza della stringa)
* P (numero di parole)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXS)


def run(N, P):
    S = []
    for i in range(P):
        S.append([choice(string.ascii_lowercase)])

    for i in range(N - (P - 1) - P):
        S[randint(0, P - 1)].append(choice(string.ascii_lowercase))

    print " ".join(["".join(v) for v in S])

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, P, S = map(int, argv[1:])

    assert 1 <= N <= MAXS
    assert N - P - (P - 1) >= 0, "Too many words"
    seed(S)
    run(N, P)
