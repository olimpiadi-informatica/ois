#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    T = int(f[0])
    assert( len(f) == T+1 )
    assert( 1 <= T <= MAXT )
    for r in f[1:]:
        riga = map(int, r.split())
        assert( len(riga) == 2 )
        assert( 1 <= riga[0] <= MAXN )
        assert( 2 <= riga[1] <= 10**riga[0] )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
