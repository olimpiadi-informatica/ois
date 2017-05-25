#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
from math import log

usage="""Generatore di "olimpo".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    tightness = randint(1,min(2**randint(1,1+int(log(N)/log(2))),N))
    chmap = ['X', 'P', 'N', 'B']
    parent = [0 for _ in xrange(N)]
    q = [0 for _ in xrange(N)]
    a = [0 for _ in xrange(N)]
    for i in xrange(1,N):
        parent[i] = randint(max(0,i-tightness),i-1)
        n = 0
        x = i
        while n < 3 and x > 0:
            x = parent[x]
            n += 1
        q[i] = randint(1,n)
        x = i
        for n in xrange(q[i]):
            x = parent[x]
        a[i] = x
    shuff = range(1,N)
    invsh = range(N)
    shuffle(shuff)
    shuff = [0] + shuff
    for i in xrange(N):
        invsh[shuff[i]] = i
    print N
    for i in xrange(1, N):
        print chmap[q[shuff[i]]], invsh[a[shuff[i]]]

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N)
