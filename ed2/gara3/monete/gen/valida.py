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
    assert( len(f) == M + 2 )
    assert( 1 <= N <= MAXN )
    assert( 0 <= M <= MAXM )
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( all([0 <= r <= MAXmonete for r in riga]) )

    s = set()
    for i in range(M):
        a, b = map(int, f[2 + i].split())
        assert( 0 <= a <= N-1 )
        assert( 0 <= b <= N-1 )
        assert( a != b )
        c = (min(a, b), max(a, b))
        assert( c not in s )
        s.add(c)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
