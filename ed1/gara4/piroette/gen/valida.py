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
    assert( len(f) == 2 )
    N = int(f[0])
    assert( 3 <= N <= MAXN )
    digits = map(int, f[1].strip().split())
    assert( all([d in range(0, 10) for d in digits]) )
    assert( sum(digits) % 9 == 0 )
    assert( 0 in digits )
    assert( 1 < len(filter(lambda x: x in [0,2,4,6,8], digits)) <= N )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
