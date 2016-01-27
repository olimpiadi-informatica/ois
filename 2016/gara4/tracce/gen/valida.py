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
    K = int(f[0])
    assert( 1 <= K <= MAXK )
    riga = list(f[1])
    assert riga[-1] == "\n"
    riga = riga[:-1]
    L = len(riga)
    assert 1 <= L <= MAXL
    assert all([int(c) in range(1, 10) for c in riga[:-1]])
    assert riga[-1] == "0"

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
