#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "nonna".

Parametri:
* N (numero di portate)
* K (numero obiettivo)
* P (massimo peso per un piatto)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= K <= %d
* 1 <= P <= %d
* K < NP
""" % (MAXN, MAXK, MAXP)

def randup(A, B):
    return max(randint(A,B), randint(A,B))

def randlow(A, B):
    return min(randint(A,B), randint(A,B))

def randlower(A, B):
    return min(randint(A,randint(A,B)), randint(A,B))

def randex(A, B, K):
    A = min(A, B)
    if (A == B == K):
        return K-1
    t = randint(A, B-(1 if A <= K <= B else 0))
    return t + (0 if t < K or K < A else 1)

def randwise(P, K, N):
    if randint(1,N) <= 5:
        return randex(1, P, K)
    if randint(1,2*N)**2 <= N:
        return randex(K/randlow(1,K), P, K)
    return randex(K+1, P, K)

def badblock(M, K, P, E):
    pp = [randint(0,K+E-(E+1)*M) for i in xrange(M-1)] + [0,K+E-(E+1)*M]
    pp.sort()
    pp = [pp[i+1]-pp[i]+E+1 for i in xrange(M)]
    for i in xrange(M):
        if pp[i] > P:
            pp[(i+1)%M] += pp[i]-P
            pp[i] = P
    return pp

def run(N, K, P):
#    print "DBG<<", (1, max(1,min(K,P)/3))
    F = P+1
    while (P/F) * N <= (K-1)/F+1:
        F = randlower(1, max(1,min(K,P)/3)) if P <= 10000 and randint(1,3)<3 else randint(1, max(1,min(K,P)/3))
    oK = max(1, K - randup(0,(K+F-1)%F))
    K = (K-1)/F+1
    P = P/F
    pp = []
    M = K+1
    E = N*P
    while max(1,K/P+1) <= min(N-len(pp),M/2):
#        print "DBG", (max(1,K/P+1), min(N-len(pp),M/2)),
        M = randlow(max(1,K/P+1), min(N-len(pp),M/2))
#        print "R", M, (1,min((K-M)/max(M-1,1),M*P-K,E)),
        E = randup(1,min((K-M)/max(M-1,1),M*P-K,E)) if M > 1 else min(P-K,E)
#        print E
        if M>1:
            pp += badblock(M, K, P, E)
    if len(pp) < N and E > 1 and randint(1,2)<2:
        pp.append(K+randlower(1,E-1))
#        print "DBG::", F, K, F*K, "Emx", E-1, "pp", pp[-1]
#    else:
#        print "DBG==", len(pp), E
    pp += [randwise(P, K, N) for i in xrange(N-len(pp))]
    shuffle(pp)
    print N, oK
    for i in pp:
        print F*i,
    print

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, K, P, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    assert (1 <= K <= MAXK)
    assert (1 <= P <= MAXP)
    assert (K < N * P)
    seed(S)
    run(N, K, P)
