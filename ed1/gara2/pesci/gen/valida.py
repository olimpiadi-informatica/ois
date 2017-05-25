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
    assert( len(f) == N + 1 )
    assert( 1 <= N <= MAXN )
    for x in f[1:]:
        riga = map(int, x.split())
        assert( len(riga) == 2 )
        assert( 0 <= riga[0] <= 1 )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
