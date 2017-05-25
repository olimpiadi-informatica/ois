#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
import string
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "acronimi".

Parametri:
* |A| (lunghezza acronimo)
* |S| (lunghezza stringa)
* X (grandezza alfabeto)
* S (seed)

Constraint:
* 1 <= |A| <= %d
* 1 <= |S| <= %d
* 1 <= X <= 26
""" % (MAXA, MAXS)


def run(K, N, X):
    alphabet = sample(string.ascii_lowercase, X)
    print "".join([choice(alphabet) for i in range(K)])
    print "".join([choice(alphabet) for i in range(N)])

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    K, N, X, S = map(int, argv[1:])

    assert (1 <= K <= MAXA)
    assert (1 <= N <= MAXS)
    assert (1 <= X <= 26)
    seed(S)
    run(K, N, X)
