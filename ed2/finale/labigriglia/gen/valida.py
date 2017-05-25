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
    assert( len(f) == N + 1 )
    assert( 1 <= N <= MAXN )
    assert( 1 <= M <= MAXN )
    for i in range(N):
        riga = map(int, f[1 + i].split())
        assert( len(riga) == M )
        assert( all([0 <= r <= 15 for r in riga]) )


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
