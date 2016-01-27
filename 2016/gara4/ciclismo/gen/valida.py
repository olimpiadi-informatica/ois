#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N, M = map(int, f[0].split())
    assert(2 <= N <= MAXN)
    assert(1 <= M <= MAXM)
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( all([0 <= r <= MAXH for r in riga]) )
    edges = map(lambda x: tuple(map(int, x.split())), f[2:])
    for e in edges:
        assert(len(e) == 2)
        assert(e[0] != e[1])
        assert(0 <= e[0] < N)
        assert(0 <= e[1] < N)
    assert(len(set(edges)) == len(edges) == M)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
