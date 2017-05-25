#!/usr/bin/env pypy

from limiti import *

import sys
import os, string

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


# 0            -> corretto
# altro numero -> non corretto
charset = string.lowercase + string.uppercase + ' ,;.!?'

def run(f, st):
    assert( len(f) == 2 )
    N, K = map(int, f[0].split())
    assert( 2 <= N <= MAXN and 2 <= K <= N)
    values = map(int, f[1].split())
    assert all([1 <= c <= MAXD for c in values])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
