#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


# 0            -> corretto
# altro numero -> non corretto
def run(f, st):
    assert( len(f) == 2 )
    N, M, K = map(int, f[0].split())
    assert (1 <= N <= MAXN)
    assert (1 <= M <= K <= MAXK)
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( all([1 <= r <= K-1 for r in riga]) )
    assert( all([riga[i] < riga[i+1] for i in xrange(N-1)]) )
    riga = [0] + riga + [K]
    assert( all([riga[i+1]-riga[i] <= M for i in xrange(N+1)]) )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
