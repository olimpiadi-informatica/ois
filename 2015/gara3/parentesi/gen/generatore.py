#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

sys.setrecursionlimit(10**5)

usage="""Generatore di "parentesi".

Parametri:
* N (lunghezza espressione)
* T (tonde: 0 - tutte le parentesi, 1 - solo tonde)
* R (restrizioni random: 0 - random, 1 - gerarchico benformato, 2 - benformato, 3 - malformato)
* P (percentuale di innestamento per T=1-3)
* S (seed)

Constraint:
* 1 <= N <= %d
* 0 <= T <= 1
* 0 <= R <= 3
* 0 <= P <= 100
""" % (MAXN)

v = '{[(<}])>'
NN = 0

def genera(N, P, f):
    if N == 0:
        return [];
    r = random()
    r = int(N*P/(2*(1-P))*r)*2 if r < 1-P else int(N/(P+0.000001)*(P-0.5+(1-P)*r/2))*2
    c = randint(0,3)
    E = [v[c]] + f(r, P, f) + [v[c+4]]
    return E + f(N-r-2, P, f) if random() < 0.5 else f(N-r-2, P, f) + E

def benformata(N, P):
    return genera(N, P, genera)

def malformata(N, P, f = None):
    if N == 0:
        return [];
    if NN*random() < 1:
        if random() < 0.9 and N >= 4:
            c = sample(xrange(4), 2)
            return [v[c[0]], v[c[1]]] + genera(N-4, P, malformata) + [v[c[0]+4], v[c[1]+4]]
        else:
            c = randint(0,3)
            return [v[c+4]] + genera(N-2, P, malformata) + [v[c]]
    else:
        return genera(N, P, malformata)

def check(E):
    Stack = []
    for c in E:
        if c in v[:4]:
            Stack.append(c)
        elif len(Stack) == 0:
            return False
        elif [i for i in xrange(4,8) if v[i] == c][0] == [i+4 for i in xrange(4) if v[i] == Stack[-1]][0]:
            Stack.pop()
        else:
            return False
    return len(Stack) == 0

def run(N, T, R, P):
    print N
    if R == 0:
        print ''.join([choice(v) for i in xrange(N)])
        return
    if R == 1:
        K = [0, 0, 0, 0]
        E = []
        for i in xrange(N):
            if sum(K) == 0:
                c = int(random()**2 * 4)
                K[c] += 1
            elif sum(K) == N-i:
                c = max([i for i in xrange(4) if K[i] > 0])+4
                K[c-4] -= 1
            elif random() < P:
                c = max([i for i in xrange(4) if K[i] > 0])
                if (2 + (N-2)*P) * random() < 6:
                    c += int(random()**2 * (4-c))
                K[c] += 1
            else:
                c = max([i for i in xrange(4) if K[i] > 0])+4
                K[c-4] -= 1
            E.append(v[c])
        print ''.join(E)
        return
    if R == 2:
        print ''.join(benformata(N, P))
        return
    if R == 3:
        if T == 1:
            split = 2*randint(0,N/2-1)
            print ''.join(benformata(split, P) + [')', '('] + benformata(N-split-2, P))
            return
        E = malformata(N, P)
        while check(E):
            E = malformata(N, P)
        print ''.join(E)
        return

if __name__ == "__main__":
    if len(argv) != 6:
        print usage
        exit(1)

    N, T, R, P, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (0 <= T <= 1)
    assert (0 <= R <= 3)
    assert (0 <= P <= 100)
    NN = N
    if T == 1:
        v = '(((())))'
    seed(S)
    run(N, T, R, P*0.01)
