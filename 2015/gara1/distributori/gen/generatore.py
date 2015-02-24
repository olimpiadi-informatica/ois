#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "distributori".

Parametri:
* N (numero di distributori)
* M (km con un pieno)
* K (km per il viaggio)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= M <= K <= %d
* N < K <= (N+1)*M
""" % (MAXN, MAXK)


def run(N, M, K):
    D = []
    for i in xrange(10+100000/N):
        t = sample(xrange(1,K),N)
        t.sort()
        D.append((max(max([0]+[t[i+1]-t[i] for i in xrange(N-1)]),t[0],K-t[-1]), t))
        if D[-1][0] == M:
            break
    D = min(D)
    M = max(M, D[0])
    print N, M, K
    for i in D[1]:
        print i,
    print

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, M, K, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= M <= K <= MAXK)
    assert (N < K <= (N+1)*M)
    seed(S)
    run(N, M, K)
