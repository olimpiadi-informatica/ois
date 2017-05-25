#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os, string
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "remix".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)

def word(maxl = 10):
    l = randint(1, maxl)
    return ''.join(choice(string.letters) for _ in range(l))

def run(N):
    pah = 'PaH'
    tunz = 'TuNZ'

    cur_len = 0
    words = []
    maxl = 10

    while True:
        if cur_len == N:
            break

        if randint(0, 1) == 0:
            # Azione 1: aggiungi parola
            w = word(min(maxl, N - cur_len))
            if cur_len + len(w) > N:
                break
            words += [w]
            cur_len += len(w)
            if randint(0, 1) == 0:
                if cur_len + len(pah) > N:
                    break
                words += [pah]
                cur_len += len(pah)
            else:
                if cur_len + len(tunz) > N:
                    break
                words += [tunz]
                cur_len += len(tunz)
        else:
            # Azione 2: aggiungi pah
            # Azione 3: aggiungi tunz
            pos = randint(0, len(words))
            if randint(0, 1) == 0:
                if cur_len + len(pah) > N:
                    break
                words.insert(pos, pah)
                cur_len += len(pah)
            else:
                if cur_len + len(tunz) > N:
                    break
                words.insert(pos, tunz)
                cur_len += len(tunz)
    print cur_len
    print ''.join(words)

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
