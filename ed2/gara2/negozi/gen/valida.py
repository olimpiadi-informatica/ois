#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N, Q = map(int, f[0].split())
    assert( len(f) == 2 + Q )
    assert( 1 <= N <= MAXN )
    assert( 1 <= N <= MAXQ )
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( all([0 <= r < MAXT for r in riga]) )

    types_set = set(riga)
    for i in xrange(Q):
        a, b = map(int, f[2+i].split())
        assert 0 <= a < N
        assert b in types_set

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
