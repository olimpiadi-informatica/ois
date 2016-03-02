#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "filiali".

Parametri:
* N (numero di citta')
* F (numero di filiali)
* S (seed)

Constraint:
* 1 <= F <= N <= %d
* F <= %d
""" % (MAXN, MAXF)


def run(N, F):
    K = randint(1,MAXK)
    print N, F
    l = [randint(0,K) for _ in xrange(N)]
    l.sort()
    for i in l:
        print i,
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, F, S = map(int, argv[1:])

    assert (1 <= F <= N <= MAXN)
    assert (F <= MAXF)
    seed(S)
    run(N, F)
