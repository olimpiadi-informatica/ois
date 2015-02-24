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
    N = int(f[0])
    assert( 1 <= N <= MAXN )
    assert (len(f) == N + 1)
    for r in f[1:]:
        riga = map(int, r.split())
        assert( len(riga) == 3 )
        assert( 1 <= riga[0] <= MAXT )
        assert( 1 <= riga[1] <= MAXT )
        assert( 1 <= riga[2] <= MAXC )
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
