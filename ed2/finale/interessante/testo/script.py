#!/usr/bin/env pypy

from sys import argv, setrecursionlimit


count = 0
l = []
Kmin = {}
Kmax = {}

def backtrack(N, left, skip = False):
    global l, count
    if count >= 100000:
        print "troppe!"
        return True
    if len(l) == N:
        count += 1
        if not skip and False:
            if count < 10:
                print '\t', ''.join(map(str,l))
            if count == 10:
                print '\t', '...'
        return skip
    if len(l) > 0 and not (Kmin[N-len(l)] <= left <= Kmax[N-len(l)]):
        return False
    ok = [True, True]
    for i in xrange(1,min(len(l)/3+1,11)):
        if l[-i] == l[-2*i] == l[-3*i]:
            ok[l[-i]] = False
    if left == 0:
        ok[1] = False
    if len(l)+left == N:
        ok[0] = False
    if ok[0]:
        l.append(0)
        if backtrack(N, left, skip):
            return True
        l.pop()
    if ok[1]:
        l.append(1)
        if backtrack(N, left-1, skip):
            return True
        l.pop()

MaxN = int(argv[1])
Kmin[0] = Kmax[0] = 0
for N in xrange(1,MaxN+1):
    for K in xrange(Kmin[N-1],N+1):
        l = []
        count = 0
        backtrack(N, K, True)
        if count > 0:
            Kmin[N] = K
            Kmax[N] = N-Kmin[N]
            break
for i in xrange(len(Kmin)):
    print '%3d : %3d - %-3d   ' % (i, Kmin[i], Kmax[i]),
    if i%6 == 4:
        print
print
# asintotically: Kmin[i] = 0.454i-1

setrecursionlimit(MaxN+10)
for i in xrange(Kmin[MaxN],MaxN/2+1):
    raw_input()
    l = []
    count = 0
    backtrack(MaxN, i)
    print i, ':', count
