#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
import string

usage="""Generatore di "capslock".

Parametri:
* N (numero di caratteri)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)

charset = string.lowercase + string.uppercase + ' .,:;!?'

def run(N):
    print N
    s = bytearray()
    for i in xrange(N):
        s += choice(charset)
    print str(s)

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    seed(S)
    run(N)
