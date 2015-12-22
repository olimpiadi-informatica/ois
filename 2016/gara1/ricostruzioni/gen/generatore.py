#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "ricostruzioni".

Parametri:
* N (lunghezza linea)
* K (lunghezza server)
* H (altitudine massima)
* S (seed)

Constraint:
* 1 <= K <= N <= %d
* 0 <= H <= %d
""" % (MAXN, MAXH)


def run(N, K, H):
    print N, K
    for i in xrange(N):
        print randint(0,H),
    print

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, K, H, S = map(int, argv[1:])

    assert (1 <= K <= N <= MAXN)
    assert (0 <= H <= MAXH)
    seed(S)
    run(N, K, H)
