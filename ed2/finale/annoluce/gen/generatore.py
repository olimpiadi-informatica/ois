#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
import math

usage="""Generatore di "annoluce".

Parametri:
* N (numero stelle)
* Q (numero query)
* E (estremo delle coordinate)
* QP (probabilita' che capiti una quadrupla pitagorica 0-100)
* T (tipo: 0 normale, 1 monodimensionale, 2 bidimensionale)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= Q <= %d
* 1 <= E <= %d
""" % (MAXN, MAXQ, MAXC)


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def get_pythagorean_quadruple(E):
    m, n, p, q = 0, 0, 0, 0

    a = lambda: abs(m*m + n*n - p*p - q*q)
    b = lambda: abs(2*(m*q + n*p))
    c = lambda: abs(2*(n*q - m*p))
    d = lambda: abs(m*m + n*n + p*p + q*q)

    domain = range(MINC, int(E ** 0.5) // 2)

    while 1:
        m = choice(domain)
        n = choice(domain)
        p = choice(domain)
        q = choice(domain)

        if gcd(m, gcd(n, gcd(p, q))) == 1 and (m + n + p + q) % 2 == 1:
            return a(), b(), c(), d()


def run(N, Q, E, QP, T):
    stars = [(0, 0, 0)]
    quads = []

    print N
    for i in xrange(N - len(stars)):  # -1 because (0, 0, 0) is already there
        if random() < QP / 100:
            quads.append(get_pythagorean_quadruple(E))
            star = [quads[-1][0], quads[-1][1], quads[-1][2]]
        else:
            star = [randint(MINC, E), randint(MINC, E), randint(MINC, E)]

        if T == 1:
            star[1] = 0
            star[2] = 0
        elif T == 2:
            star[2] = 0

        stars.append(tuple(star))

    shuffle(stars)
    for s in stars:
        print " ".join(map(str, s))

    print Q
    MAXQUERY = int(math.hypot(E, math.hypot(E, E)))
    for i in xrange(Q):
        if random() < QP / 100:
            print choice(quads)[3]
        else:
            print int(random() * MAXQUERY)

if __name__ == "__main__":
    if len(argv) != 7:
        print usage
        exit(1)

    N, Q, E, QP, T, S = map(int, argv[1:])

    assert 1 <= N <= MAXN
    assert 1 <= Q <= MAXQ
    assert 1 <= E <= MAXC
    assert 0 <= QP <= 100
    assert 0 <= T <= 2
    seed(S)
    run(N, Q, E, QP, T)
