#!/usr/bin/env pypy

from limiti import *

import sys
import os
from string import ascii_lowercase

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    assert( len(f) == 3 )
    N = int(f[0])
    assert( 1 <= N <= MAXN )
    G, W = f[1], f[2]
    assert( G[-1] == W[-1] == "\n" )
    G = G[:-1]
    W = W[:-1]
    assert( len(G) == len(W) == N )
    assert( all([c in ascii_lowercase for c in G]) )
    assert( all([c in ascii_lowercase for c in W]) )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
