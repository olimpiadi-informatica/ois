#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "strudel".

Parametri:
* N (numero)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    A, B = sorted([randint(1, N-2) for _ in xrange(2) ]) if N > 2 else [0,0]
    m = [randint(0, MAXV*(10+abs(i-N/2))/(10+(N+1)/2)) for i in xrange(N)]
    c = [randint(0, MAXV-(MAXV-10)*(abs(i-N/2))/((N+1)/2)) for i in xrange(N)]
    i = randint(B+1,N+A-1)%N if A>0 and B<N-1 else randint(0, N-1)
    c[i] = randint(m[i],MAXV)
    if A > 0 and B < N-1:
        s = [c[i]-m[i] for i in xrange(N)]
        for i in xrange(1,N):
            s[i] += s[i-1]
        D = max(s[B+1:]) + 1 - min(min(s[:A]),0)
        r = range(A,B+1)
        shuffle(r)
        for _ in xrange(10):
            if D <= 0:
                break
            for i in r:
                ss = c[i] - m[i]
                m[i] = randint(m[i], MAXV)
                c[i] = randint(0, c[i])
                D -= ss-c[i]-m[i]
                if D <= 0:
                    break
        if D > 0 and False:
            run(N)
            return
        s = [c[i]-m[i] for i in xrange(N)]
        for i in xrange(1,N):
            s[i] += s[i-1]
        #assert(min(min(s[:A]),0) > max(s[B+1:]))
    else:
        assert(N<10)
    print N
    print ' '.join(map(str, m))
    print ' '.join(map(str, c))

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
