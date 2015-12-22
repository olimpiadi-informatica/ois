#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "carrucole".
    
    Parametri:
    * N (numero di nodi del grafo)
    * M (numero di archi del grafo)
    * S (seed)
    
    Constraint:
    * 2 <= N <= %d
    * 1 <= M <= %d
    * M <= N*(N-1)/2
    """ % (MAXN, MAXM)

def run(N, M):
    p = randint(0,100)
    print N, M
    for i in xrange(N):
        print 0 if randint(0,99) < p else 1,
    print
    for i in xrange(M):
        print randint(0,N-1), randint(0,N-1)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    assert (M <= N*(N-1)/2)
    seed(S)
    run(N, M)
