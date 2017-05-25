#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "ruspa".

Parametri:
* N (muri)
* T (test)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= T <= %d
""" % (MAXN, MAXT)


def run(N, T):
    print N, T
    MX = sample(range(-MAXM,MAXM+1), N+T)
    X = sorted(sample(MX, T))
    M = sorted(set(MX) - set(X))
    for i in xrange(N):
        print M[i],
    print
    for i in xrange(T):
        print X[i], randint(0,1)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, T, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (1 <= T <= MAXT)
    seed(S)
    run(N, T)
