#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "combinazione".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    mx = randint(N,MAXN);
    nums = sample(xrange(1,mx+1),N);
    print N
    for i in xrange(N):
        print nums[i],
    print

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N)
