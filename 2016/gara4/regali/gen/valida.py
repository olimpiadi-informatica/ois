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
    assert( 2 <= N <= MAXN )
    assert( 1 <= Q <= MAXQ )
    assert( len(f) == N+1 )
    for r in f[1:]:
        riga = map(int, r.split())
        assert( len(riga) == Q )
        assert( all([1 <= r <= MAXG for r in riga]) )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
