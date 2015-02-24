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
    assert(1 <= N <= MAXN)
    B, C = map(int, f[1].split())
    assert(0 <= B <= MAXB)
    assert(C == -1)
    for riga in f[2:]:
        B, C = map(int, riga.split())
        assert(0 <= B <= MAXB)
        assert(0 <= C <= N-1)
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
