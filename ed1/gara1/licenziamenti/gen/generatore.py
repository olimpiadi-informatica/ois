#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "licenziamenti".

Parametri:
* N (numero di persone)
* H (altezza minima garantita)
* S (seed)

Constraint:
* 1 <= H <= N <= %d
""" % (MAXN)

def run(N, H):
    B = randint(1, MAXB)
    C = range(-1,H-1) + [randint(0,i-1) for i in xrange(H, N)]
    perm = range(1,N)
    if H < N:
        shuffle(perm)
    perm = [0] + perm
    inv = range(N)
    for i in xrange(N):
        inv[perm[i]] = i
    print N
    print randint(0,B), -1
    for i in xrange(1, N):
        print randint(0,B), inv[C[perm[i]]]

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, H, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= H <= N <= MAXN)
    seed(S)
    run(N, H)
