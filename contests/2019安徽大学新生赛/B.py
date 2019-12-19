t = int(input())
for cas in range(t):
    arr = list(map(int, input().split()))
    arr.sort()
    *a, b, c = arr
    if sum(a) == b == c:
        print(c)
    else:
        print(-1)
