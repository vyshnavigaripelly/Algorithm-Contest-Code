n = int(input())
s = input()
for k in [x for x in range(1, n + 1) if n % x == 0]:
    s = s[k - 1::-1] + s[k:]
print(s)
