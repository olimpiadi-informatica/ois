#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "magneti".

Parametri:
* M (numero di magneti => N = 4 * M)
* S (seed)

Constraint:
* 1 <= M <= %d
""" % (MAXM)


def run(M):
    print 4 * M
    s = ''
    for i in xrange(M):
        s += choice(['(+-)', '(-+)'])
    print s

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    M, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= M <= MAXM)
    seed(S)
    run(M)
