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
    N = int(f[0])
    assert(N % 4 == 0)
    M = N/4
    assert( 1 <= M <= MAXM )
    riga = f[1].strip()
    assert( len(riga) == N )
    for i in xrange(0, N, 4):
        assert( riga[i:i+4] in ('(+-)', '(-+)') )
    return 0

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
