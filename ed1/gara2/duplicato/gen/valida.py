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
    if st <= 3:
        MAXP = 100000
    else:
        MAXP = 1000000000

    assert( len(f) == 2 )
    N = int(f[0])
    assert( MINN <= N <= MAXN )
    riga = map(int, f[1].split())
    assert( len(riga) == 2*N - 1 )
    assert( all([1 <= r <= MAXP for r in riga]) )

    # Controlla che ogni numero compaia esattamente due volte, tranne uno che compare esattamente una volta
    d = {}
    for x in riga:
        if x not in d:
            d[x] = 1
        else:
            d[x] += 1
    howmany1 = 0
    for k, v in d.items():
        assert 1 <= v <= 2
        if v == 1:
            howmany1 += 1
    assert howmany1 == 1

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
