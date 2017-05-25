#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    assert( len(f) == 1 )
    assert( 1 <= len(f[0]) <= MAXN+1 )
    assert( f[0][-1] == "\n" )
    v = map(int, f[0].split("x"))
    assert( all([1 <= x <= 1000000 for x in v]) )

    if st == 2:
        # Il risultato sta in un long long
        assert( reduce(lambda x, y: x*y, v) < 2**31 )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
