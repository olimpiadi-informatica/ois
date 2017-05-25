#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    assert( len(f) == 2 )
    N, F = map(int, f[0].split())
    assert( 1 <= F <= MAXF )
    assert( 1 <= N <= MAXN )
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( 0 <= riga[0] <= riga[N-1] <= MAXK )
    assert( all([riga[i] <= riga[i+1] for i in xrange(N-1)]) )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
