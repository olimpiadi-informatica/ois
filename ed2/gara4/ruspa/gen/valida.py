#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N, T = map(int, f[0].split())
    assert( 1 <= N <= MAXN )
    assert( 1 <= T <= MAXT )
    assert( len(f) == T+2 )
    M = map(int, f[1].split())
    assert( len(M) == N )
    for i in xrange(N-1):
        assert(M[i] < M[i+1])
    assert( -MAXM <= M[0] <= M[-1] <= MAXM )
    M = set(M)
    for r in f[2:]:
        X, O = map(int, r.split())
        assert( -MAXM <= X <= MAXM )
        assert(X not in M)
        assert(0 <= O <= 1)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
