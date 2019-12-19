# input = raw_input

for cas in range(int(input())):
    n = int(input()) + 1
    l, r = 0, n
    while l < r:
        m = (l + r) // 2
        ans = m * m
        if ans >= n:
            r = m
        else:
            l = m + 1
    print(1 if l % 2 == 0 else 0)