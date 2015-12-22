#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "ricarica".

Parametri:
* N (intervalli)
* M (minuti)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N, M):
    x = [randint(1,M-N+1) for _ in xrange(2*N)]
    x.sort()
    print N, M
    for i in xrange(N):
        print x[2*i]+i, x[2*i+1]+i

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    seed(S)
    run(N, M)
