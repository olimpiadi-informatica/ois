from string import lowercase, uppercase

s = open("input.txt").readlines()[1].strip()
ans = bytearray()
for c in s:
    if c in lowercase:
        ans += c.upper()
    elif c in uppercase:
        ans += c.lower()
    else:
        ans += c
open("output.txt", "w").write("%s\n" % str(ans))
