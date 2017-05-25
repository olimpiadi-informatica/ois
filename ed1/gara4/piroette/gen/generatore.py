#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "piroette".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 3 <= N <= %d
""" % (MAXN)


def run(N):
    digits = [0] # Metti lo 0
    min_even = randint(0,4)*2
    digits.append(min_even) # Metti un altro pari
    for i in xrange(N-3):
        digits.append(randint(min_even/2,4)*2 if randint(0,1) == 1 else randint(0,4)*2+1)
    digits.append(9 - sum(digits) % 9) # Nota: non possono essere _tutti_ 0
    shuffle(digits)
    x = choice([i for i in xrange(N) if digits[i]>0])
    digits[0], digits[x] = digits[x], digits[0]
    print N
    print ' '.join(map(str,digits))

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (3 <= N <= MAXN)
    seed(S)
    run(N)
