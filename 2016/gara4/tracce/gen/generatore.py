#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "tracce".

Parametri:
* K (lunghezza sequenze)
* L (lunghezza stringa)
* S (seed)

Constraint:
* 1 <= K <= %d
* 1 <= L <= %d
* L <= K
""" % (MAXK, MAXL)


def run(K, L):
    print K
    print "".join([str(randint(1, 9)) for i in xrange(L - 1)] + ["0"])

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    K, L, S = map(int, argv[1:])

    assert (1 <= K <= MAXK)
    assert (1 <= L <= MAXL)
    assert (L <= K)
    seed(S)
    run(K, L)
