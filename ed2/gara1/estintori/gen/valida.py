#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def run(f, st):
    R, C = map(int, f[0].split())
    assert( 1 <= R <= MAXR )
    assert( 1 <= C <= MAXC )
    assert( len(f) == R + 1 )

    M = []
    for i in xrange(1, R+1):
        assert( f[i][-1] == "\n" )
        f[i] = f[i][:-1]
        assert( len(f[i]) == C )

        if st == 3:
            # Il subtask 3 garantisce che non ci sono estintori
            assert( set(f[i]).issubset(set("#.")) )
        else:
            assert( set(f[i]).issubset(set("#.@")) )

        M.append(f[i])

    assi_x = []
    for i in xrange(R):
        if all([c == "#" for c in M[i]]):
            assi_x.append(i)

    assi_y = []
    for j in xrange(C):
        Mj = [M[i][j] for i in xrange(R)]
        if all([c == "#" for c in Mj]):
            assi_y.append(j)

    assert( 0 in assi_x )
    assert( R-1 in assi_x )
    assert( 0 in assi_y )
    assert( C-1 in assi_y )

    for j in xrange(C):
        asse_y = filter(lambda i: M[i][j] == "#", range(R))
        if asse_y != range(R):
            assert( asse_y == assi_x )

    for i in xrange(R):
        asse_x = filter(lambda j: M[i][j] == "#", range(C))
        if asse_x != range(C):
            assert( asse_x == assi_y )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
