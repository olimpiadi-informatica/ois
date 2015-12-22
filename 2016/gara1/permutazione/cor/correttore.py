#!/usr/bin/env python2

import sys
from string import ascii_uppercase

if len(sys.argv) != 4:
    print("Usage: correttore <input> <correct output> <test output>")
    sys.exit(1)

try:
    with open(sys.argv[1], "r") as fin:
        K = int(fin.read())
        with open(sys.argv[3], "r") as fout:
            line = fout.readlines()[0].strip()
            if len(line) != 26 or any([x not in line for x in ascii_uppercase]):
                print "0.0"
                print >> sys.stderr, "Output malformato"
            else:
                s = set()
                for i in range(1, 26):
                    s.add(abs(ord(line[i]) - ord(line[i-1])))
                if len(s) != K:
                    print "0.0"
                    print >> sys.stderr, "La funzione espotenziale non vale K"
                else:
                    print "1.0"
                    print >> sys.stderr, "Output corretto"
except:
    print "0.0"
    print >> sys.stderr, "Output malformato"
