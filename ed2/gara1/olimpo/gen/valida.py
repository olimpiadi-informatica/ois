#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N = int(f[0])
    assert( len(f) == N )
    assert( 1 <= N <= MAXN )
    for r in f[1:]:
        Q, A = r.split()
        A = int(A)
        assert( len(r.split()) == 2 )
        assert( 0 <= A <= N-1 )
        assert(Q in ['P', 'N', 'B'])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
