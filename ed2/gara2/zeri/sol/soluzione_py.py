#!/usr/bin/env python2

s = str(eval("*".join(raw_input().split("x"))))[::-1]

ans = 0
for c in s:
    if c == "0":
        ans += 1
    else:
        break

print ans
