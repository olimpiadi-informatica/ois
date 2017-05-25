#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
import string
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "enciclopedia".

Parametri:
* N (numero di parole)
* K (numero di volumi)
* A (grandezza alfabeto)
* S (seed)

Constraint:
* 4 <= N <= %d
* 2 <= K < N
* N %% K == 0
* A <= 26
""" % (MAXN)

def randword(alfabeto):
    return "".join([choice(alfabeto) for i in range(randint(1, MAXC))])

def run(N, K, A):
    print N, K

    alfabeto = sample(string.ascii_lowercase, A)

    already = set()
    lista = []
    for i in xrange(N):
        word = randword(alfabeto)
        while word in already:
            word = randword(alfabeto)
        lista.append(word)
        already.add(word)
    lista.sort()

    for word in lista:
        print word

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, K, A, S = map(int, argv[1:])

    assert (4 <= N <= MAXN)
    assert (2 <= K < N)
    assert (N % K == 0)
    assert (A <= 26)
    seed(S)
    run(N, K, A)
