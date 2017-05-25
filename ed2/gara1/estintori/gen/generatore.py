#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import uniform, randint, choice, sample, shuffle, seed

usage="""Generatore di "estintori".

Parametri:
* R (righe)
* C (colonne)
* RR ("riempimento" in temini di righe)
* CC ("riempimento" in termini di colonne)
* ST (probabilità che una stanza riceva un estintore)
* S (seed)

Constraint:
* 1 <= R <= %d
* 1 <= C <= %d
* 0 <= RR <= 1
* 0 <= CC <= 1
* ST <= 1
""" % (MAXR, MAXC)


def run(R, C, RR, CC, ST):
    print R, C

    assi_x = set(sample(range(1, (R-1)/2), int(RR * (R-1)/2)))
    assi_y = set(sample(range(1, (C-1)/2), int(CC * (C-1)/2)))

    assi_x = [0] + sorted(map(lambda x: x * 2, list(assi_x))) + [R-1]
    assi_y = [0] + sorted(map(lambda y: y * 2, list(assi_y))) + [C-1]

    M = []

    for i in xrange(1, len(assi_x)):
        M.append(["#"] * C)
        for ii in xrange(assi_x[i-1]+1, assi_x[i]):
            line = ["#"]
            for j in xrange(1, len(assi_y)):
                for jj in xrange(assi_y[j-1]+1, assi_y[j]):
                    line.append(".")
                line.append("#")
            M.append(line)
    M.append(["#"] * C)

    for i in xrange(1, len(assi_x)):
        for j in xrange(1, len(assi_y)):
            while uniform(0, 1) < ST:
                x = randint(assi_x[i-1]+1, assi_x[i]-1)
                y = randint(assi_y[j-1]+1, assi_y[j]-1)
                M[x][y] = "@"

    for line in M:
        print "".join(line)

if __name__ == "__main__":
    if len(argv) != 7:
        print usage
        exit(1)

    R, C, RR, CC, ST, S = argv[1:]
    R = int(R)
    C = int(C)
    RR = float(RR)
    CC = float(CC)
    ST = float(ST)

    assert (1 <= R <= MAXR)
    assert (1 <= C <= MAXC)
    assert (0 <= RR <= 1)
    assert (0 <= CC <= 1)
    assert (ST <= 1)
    seed(S)
    run(R, C, RR, CC, ST)
