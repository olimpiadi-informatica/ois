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
    N, M = map(int, f[0].split())
    if not MINN <= N <= MAXN:
        return 1
    if not MINM <= M <= MAXM:
        return 2
    edges = map(lambda x: map(int, x.split()), f[1:])
    for e in edges:
        e.sort()
        if (not 1 <= e[0] <= N) or (not 1 <= e[1] <= N) or e[0] == e[1]:
            return 3
    if not (len(set(map(lambda e: e[0]*N+e[1], edges))) == len(edges) == M):
        return 4
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
