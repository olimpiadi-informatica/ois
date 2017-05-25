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
    assert( len(f) == M+2 )
    assert( len(f[1]) == N+1 )
    assert( all([c in 'RLFBX' for c in f[1][:-1]]) )
    for r in f[2:]:
        riga = map(int, r.split())
        assert( len(riga) == 2 )
        assert( 0 <= riga[0] <= riga[1] < N )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
