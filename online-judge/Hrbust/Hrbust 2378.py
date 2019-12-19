import re
import sys

if sys.winver[0] == '2':
    input = raw_input

for cas in range(int(input())):
    ans = set()
    for i in range(int(input())):
        s = input()
        tmp = re.findall(r'[^-_a-zA-Z0-9]@[-_a-zA-Z0-9]+', ' ' + s + ' ')
        for x in tmp:
            ans.add(x[1:].replace('@', '').strip())
    ans = sorted(list(ans))
    print(len(ans))
    for i in ans:
        print(i)
