#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "zeri".

Parametri:
* N (lunghezza della stringa)
* S (seed)
* NO5 (booleano)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N, NO5):
    if NO5:
        int1 = [0, 1, 2, 3, 4, 6, 7, 8, 9]
        int2 = [1, 2, 3, 4, 6, 7, 8, 9]
    else:
        int1 = range(10)
        int2 = range(1, 10)

    v = map(str, [choice(int1)] + [choice(int2) for i in xrange(N - 1)])

    out = set()
    for i in xrange(N):
        if i-1 not in out and i+1 not in out and i not in (0, N - 1):
            # Must not have holes longer than 5 (because 5 digits is 99999, almost 10^6)
            if i >= 5 and i-2 not in out and i-3 not in out and i-4 not in out and i-5 not in out:
                v[i] = "x"
                out.add(i)
            elif random() < 0.3:  # Also do it with some probability
                v[i] = "x"
                out.add(i)

    # Fix leading zeroes
    leading = False
    for i in xrange(1, N):
        if v[i] == "0" and v[i-1] == "x":
            leading = True
        if v[i] == "0" and leading:
            v[i] = str(choice(int2))
        else:
            leading = False

    print "".join(v)



if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, S, NO5 = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N, NO5 == 1)
