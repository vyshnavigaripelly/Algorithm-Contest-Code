import math

t = int(input())
for cas in range(t):
    x, y = map(int, input().split())
    g = math.gcd(x, y)
    if g == 1:
        print('%d %d %d' % (y / g, x / g, x * y / g))
    else:
        print(-1)
