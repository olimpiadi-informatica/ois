#!/usr/bin/env python2

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

num_righe = None
num_colonne = None
S = None

# 0            -> corretto
# altro numero -> non corretto
def run(f, st):
    N = int(f[0])
    if not MINN <= N <= MAXN:
        return 1
    vals = map(int, f[1].split())
    for v in vals:
        if not 1 <= v <= N:
            return 2
    if len(set(vals)) == len(vals):
        return 3
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
