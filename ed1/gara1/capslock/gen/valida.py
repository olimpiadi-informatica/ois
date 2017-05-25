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
charset = string.lowercase + string.uppercase + ' .,:;!?'

def run(f, st):
    assert( len(f) == 2 )
    N = int(f[0])
    assert( 1 <= N <= MAXN )
    text = f[1]
    assert(text[-1] == '\n')
    text = text[:-1]
    assert( len(text) == N )
    assert all([c in charset for c in text])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
