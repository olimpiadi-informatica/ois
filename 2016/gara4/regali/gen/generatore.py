#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "regali".

Parametri:
* N (giocattoli)
* Q (qualita)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= Q <= %d
""" % (MAXN,MAXQ)


def run(N, Q):
    print N, Q
    for i in xrange(N):
        for i in xrange(Q):
            print randint(1,MAXG),
        print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, Q, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= Q <= MAXQ)
    seed(S)
    run(N, Q)
