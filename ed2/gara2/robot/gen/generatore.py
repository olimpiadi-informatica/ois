#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "robot".

Parametri:
* C (charset ammesso)
* S (seed)

Constraint:
* '' < C <= '%s'
""" % (CHARSET)

def muovi(x, y, d, N, M):
    d = (d+4)%4
    if (d%2):
        y += d-2;
    else:
        x += 1-d;
    x = (x+M)%M
    y = (y+N)%N
    return x, y, d

def run(C):
    CX = list(set(C)-set('X'))
    N = randint(1, MAXN)
    M = randint(1, MAXN)
    T = [[choice(CX) for i in xrange(M)] for j in xrange(N)]
    if C == 'X+O' and randint(0,1):
        T[0][-1] = 'O'
    if 'X' in C:
        if S%2 == 0:
            p=randint(1,30)
            for i in xrange(N):
                for j in xrange(M):
                    if randint(0,100)<p:
                        T[i][j] = 'X'
        else:
            V = [[[0, 0, 0, 0] for i in xrange(M)] for j in xrange(N)]
            x, y, d = 0, 0, 0
            while V[y][x][d] == 0:
                V[y][x][d] = 1
                if T[y][x] == 'L':
                    d += 1
                if T[y][x] == 'R':
                    d -= 1
                if T[y][x] == 'O':
                    x, y, d = muovi(x, y, d, N, M)
                x, y, d = muovi(x, y, d, N, M)
            p=randint(1,30)
            for i in xrange(N):
                for j in xrange(M):
                    if randint(0,100)<p and sum(V[i][j]) == 0:
                        T[i][j] = 'X'
    print N, M
    for r in T:
	print ''.join(r)

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    C = argv[1]
    S = int(argv[2])

    assert (len(C) > 0)
    assert (set(C) <= set(CHARSET))
    seed(S)
    run(C)
