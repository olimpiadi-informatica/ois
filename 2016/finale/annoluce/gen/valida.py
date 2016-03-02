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
    assert( 1 <= N <= MAXN )

    if st == 5:
        assert N <= 100

    for i in range(N):
        x, y, z = map(int, f[1 + i].split())
        assert MINC <= x <= MAXC
        assert MINC <= y <= MAXC
        assert MINC <= z <= MAXC

        if st == 2:
            assert y == 0
            assert z == 0
        elif st == 3:
            assert z == 0

    Q = int(f[N + 1])
    assert( 1 <= Q <= MAXQ )

    if st == 4:
        assert N <= 10
        assert Q <= 10
    elif st == 6:
        assert Q <= 100

    for i in range(Q):
        y = int(f[N + 2 + i])
        assert 0 <= y <= MAXY

        if st == 4:
            assert y <= 10
        elif st == 5 or st == 6:
            assert y <= 10000

    assert( len(f) == N + Q + 2 )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])
        assert 1 <= st <= 7

    f = open(sys.argv[1]).readlines()
    run(f, st)
