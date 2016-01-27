#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
from sortedcontainers import SortedSet

usage="""Generatore di "caffe".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    p = randint(0, 100)
    times = sorted(sample(xrange(MAXT+1), 2*N))
    tutors = []
    present = SortedSet()
    for t in times:
        if len(present) == 0 or (len(tutors) < N and randint(0,100) < p):
            present.add(len(tutors))
            tutors.append([t,-1])
        else:
            x = choice(present)
            present.discard(x)
            tutors[x][1] = t
    shuffle(tutors)
    print N
    for t in tutors:
        print t[0], t[1]

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N)
