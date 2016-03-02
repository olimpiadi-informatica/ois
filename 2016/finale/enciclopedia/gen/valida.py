#!/usr/bin/env pypy

from limiti import *

import sys
import os
import string

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N, K = map(int, f[0].split())
    assert( len(f) == 1 + N )
    assert( 4 <= N <= MAXN )
    assert( 2 <= K < N )
    assert( N % K == 0 )

    already = set()
    for i in range(N):
        assert( f[i + 1][-1] == "\n" )
        s = f[i + 1][:-1]
        assert( len(s) <= MAXC )
        assert( all([c in string.ascii_lowercase for c in s]) )
        assert( s not in already)
        already.add(s)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
