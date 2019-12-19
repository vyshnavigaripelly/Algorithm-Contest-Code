x = y = 0
ai = [0] * 107
bi = [0] * 107


def exgcd(a, b):
    global x, y
    if b == 0:
        x = 1
        y = 0
        return a
    cnt = exgcd(b, a % b)
    idx = x
    x = y
    y = idx - a // b * y
    return cnt


def excrt():
    global x, y
    x = y = 0
    M = bi[1]
    ans = ai[1]
    for i in range(2, n + 1):
        a = M
        b = bi[i]
        c = ((ai[i] - ans) % b + b) % b
        gcd = exgcd(a, b)
        idx = b // gcd
        if c % gcd != 0:
            return - 1
        x = x * (c // gcd) % idx
        ans += x * M
        M *= idx
        ans = (ans % M + M) % M
    return (ans % M + M) % M


n, m = map(int, input().split())
for i in range(1, n + 1):
    bi[i], ai[i] = map(int, input().split())
ans = excrt()
if ans == -1:
    print('he was definitely lying')
elif ans > m:
    print('he was probably lying')
else:
    print(ans)
