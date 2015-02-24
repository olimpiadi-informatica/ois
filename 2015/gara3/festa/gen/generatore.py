#!/usr/bin/env pypy

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "festa".

Parametri:
* N (numero di nodi)
* M (numero di archi)
* D (massimo grado)
* S (seed)

Constraint:
* 1 <= N <= %d
* 0 <= M <= %d
""" % (MAXN, MAXM)


def run(N,M,D):
	if M <= 1000 or M > N:
		print N, M
		deg = [0] * N
		edges = []
		for i in xrange(M):
			a = randint(0, N-1)
			while deg[a] >= D:
				a = randint(0, N-1)
			b = randint(0, N-1)
			while deg[b] >= D or b == a or (a,b) in edges or (b,a) in edges:
				b = randint(0, N-1)
			deg[a] += 1
			deg[b] += 1
			edges += [(a,b)]
			print a,b
	else:
		print N, M
		for i in xrange(M-1):
			print i, i+1
		print 0, 2


if __name__ == "__main__":
	if len(argv) != 5:
		print usage
		exit(1)

	N, M, D, S = map(int, argv[1:])

	# su seed non positivo copia un input di esempio dal .tex
	if S <= 0:
		print extract_input(True)[-S],
		exit(0)
	assert (1 <= N <= MAXN)
	assert (0 <= M <= MAXM)
	seed(S)
	run(N,M,D)
