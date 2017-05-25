#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed
from math import sqrt

usage="""Generatore di "rollercoaster".

Parametri:
* N (numero)
* T (se ci sono tratti motorizzati)
* S (seed)

Constraint:
* 10 <= N <= %d
""" % (MAXN)


def run(N, T):
    switches = set(sample(xrange(randint(1,5),N-randint(1,5)), randint(0,randint(0,randint(0,int(sqrt(N-10))))**2)))
    xstep = randint(1,randint(1,1000))
    last = randint(3000,MAXH-3000)
    lstep = 0
    T += 1
    type = randint(1,T) # 0: sali (>=) 1: scendi (<) 2+: motorizzato (con certo fattore)
    if randint(0,15) == 0:
        type = 0
    if type == 2:
        type = 2+randint(0,xstep)
        lstep = -42
    hmax = last
    print N
    print last,
    for i in xrange(N-1):
        #print (type, last, hmax, lstep)
        # applico il tipo deciso
        if type > 1:
            last += type-1
        else:
            if type == 1:
                last -= randint(1,xstep)
            else:
                step = randint(1,min(xstep,max(hmax-1-last,1)))
                if step == lstep:
                    step -= 1
                if (lstep > 0 and randint(0,10)) or (last+step >= hmax): # cambiare
                    step = 0
                last += step
                lstep = step
        last = max(min(last,MAXH),0)
        print last,
        if lstep == -42:
            lstep = type-1
            continue
        # decido se cambiare tipo
        if i in switches or (type==1 and last < 2*xstep and randint(0,10)) or (type != 1 and last+2*xstep >= hmax and randint(0,10)):
            if type == 2 and randint(0,50):
                hmax = last
                type = randint(1,2) if last+2*xstep < hmax and randint(0,10) else 1
            else:
                if type != 1:
                    hmax = last
                type = randint(0,T)
                if type == 1 and last < 2*xstep and randint(0,10):
                    type = 2*randint(0,1)
            if type == 2:
                type = 1+randint(1,xstep)
                last += type-1
                lstep = -42
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, T, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (0 <= T <= 1)
    seed(S)
    run(N, T)
