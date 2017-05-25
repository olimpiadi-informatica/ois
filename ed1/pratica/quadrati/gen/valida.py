#!/usr/bin/env python2

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
    f[0] = f[0].split()
    cond1 = int(f[0][0]) > 1000000 or int(f[0][0]) < 1
    cond2 = int(f[0][1]) > 1000000 or int(f[0][1]) < 1
    cond3 = int(f[0][0]) > int(f[0][1])

    return (cond1 or cond2 or cond3)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
