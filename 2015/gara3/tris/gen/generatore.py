#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "tris".

Parametri:
* N (numero di celle occupate)
* S (seed)

Constraint:
* 0 <= N <= %d
""" % (MAXN)

def controlla(g):
    if (g[0][0] == g[0][1] and g[0][1] == g[0][2] and g[0][0] != '.'): # Row 1
        return False
    if (g[1][0] == g[1][1] and g[1][1] == g[0][2] and g[1][0] != '.'): # Row 2
        return False
    if (g[2][0] == g[2][1] and g[2][1] == g[2][2] and g[2][0] != '.'): # Row 3
        return False

    if (g[0][0] == g[1][0] and g[1][0] == g[2][0] and g[0][0] != '.'): # Col 1
        return False
    if (g[0][1] == g[1][1] and g[1][1] == g[2][1] and g[0][1] != '.'): # Col 2
        return False
    if (g[0][2] == g[1][2] and g[1][2] == g[2][2] and g[0][2] != '.'): # Col 3
        return False

    if (g[0][0] == g[1][1] and g[1][1] == g[2][2] and g[0][0] != '.'): # Diag 1
        return False
    if (g[0][2] == g[1][1] and g[1][1] == g[2][0] and g[0][2] != '.'): # Diag 2
        return False

    return True

def run(N):
    valido = False
    griglia = []
    while not valido:
        griglia = [['.','.','.'],['.','.','.'],['.','.','.']]
        posizioni = ((0,0),(0,1),(0,2),(1,0),(1,1),(1,2),(2,0),(2,1),(2,2))
        posizioni_scelte = sample(posizioni, N)
        shuffle(posizioni_scelte)
        # Le prime floor(N/2) vanno a O, le altre ceil(N/2) a X
        for i in range(0, N/2):
            griglia[posizioni_scelte[i][0]][posizioni_scelte[i][1]] = 'O'
        for i in range(N/2, N):
            griglia[posizioni_scelte[i][0]][posizioni_scelte[i][1]] = 'X'
        valido = controlla(griglia)
    print ''.join(griglia[0])
    print ''.join(griglia[1])
    print ''.join(griglia[2])

if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (0 <= N <= MAXN)
    seed(S)
    run(N)
