#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
from string import ascii_lowercase

usage="""Generatore di "insegna".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)

def sample_with_replacements(a, num):
    ret = []
    for i in xrange(num):
        ret.append(choice(a))
    return ret

def run(N, A):
    print N
    G = sample_with_replacements(ascii_lowercase, N)
    i = randint(0, N-1)
    W = G[i:] + G[:i]

    if A == 0:
        for i in range(int(N * 0.001) + 1):
            W[randint(0, N-1)] = choice(ascii_lowercase)

    print "".join(G)
    print "".join(W)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, A, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (0 <= A <= 1)
    seed(S)
    run(N, A)
