#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "rugby".

Parametri:
* N (numero di persone)
* P (se >0 solo il presidente ha grado > 1)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)

def run(N, P):
    if P > 0:
        C = [-1]
        for i in xrange(1,N):
            if randint(0,99) < P:
                C.append(0)
            else:
                C.append(i-1)
    else:
        C = [-1] + [randint(0,i-1) for i in xrange(1, N)]
    B = [randint(1, MAXB*(N-i)/N) for i in xrange(N)]
    perm = range(1,N)
    shuffle(perm)
    perm = [0] + perm
    inv = range(N)
    for i in xrange(N):
        inv[perm[i]] = i
    print N
    print B[0], C[0]
    for i in xrange(1, N):
        print B[perm[i]], inv[C[perm[i]]]

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, P, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    seed(S)
    run(N, P)
