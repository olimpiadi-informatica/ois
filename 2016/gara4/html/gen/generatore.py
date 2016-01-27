#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "html".

Parametri:
* N (numero di caratteri)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    print N
    L = ["&"] + list("amp;" * ((N - max(2, N / 10)) / 4))
    prima = []
    dopo = []
    while len(L) + len(prima) + len(dopo) < N - 1:
        addme = [choice("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\'()*+,-./:;?@[\\]^_`{|}~ ]")]
        if len(L) + len(prima) + len(dopo) + 9 <= N - 1:
            if random() < 0.1:
                addme = list("&amp;amp;")
        if len(L) + len(prima) + len(dopo) + 5 <= N - 1:
            if random() < 0.3:
                addme = list("&amp;")

        if random() < 0.5:
            prima += addme
        else:
            dopo += addme

    print "".join(prima + L + dopo)

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N)
