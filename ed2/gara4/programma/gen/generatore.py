#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "programma".

Parametri:
* N (dimensione programma)
* M (comandi di alto livello)
* C (charset ammesso)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= M <= %d
* C <= %s
""" % (MAXN, MAXM, MAXC)

def randskip(idX, N):
    if randint(0,N-2-idX[1]+idX[0]) < idX[0]:
        return randint(0,idX[0]-1), randint(0, idX[0]-1)
    return randint(idX[1]+1,N-1), randint(idX[1]+1,N-1)

def run(N, M, C):
    print N, M
    idX = sorted(sample(xrange(N), 2))
    mX = randint(0,M)
    CX = list(set(C)-set('X'))
    s = [choice(CX) for i in xrange(N)]
    if 'X' in C:
        for i in xrange(randint(1,min(1+N/10,10+N/100,100+N/1000))):
            s[randint(idX[0],idX[1])] = 'X'
    print ''.join(s)
    for i in xrange(M):
        if i < mX:
            S, E = randskip(idX, N)
        else:
            S, E = randint(0,N-1), randint(0,N-1)
        if S > E:
            S, E = E, S
        print S, E

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, M, C, S = int(argv[1]), int(argv[2]), argv[3], int(argv[4])

    assert (1 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    assert (set(C) <= set(MAXC))
    seed(S)
    run(N, M, C)
