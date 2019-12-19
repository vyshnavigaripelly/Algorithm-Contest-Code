n = int(input())
cnt = [0] * (n + 1)
for i in range(n - 1):
    u, v = map(int, input().split())
    cnt[u] += 1
    cnt[v] += 1
print('NO' if 2 in cnt else 'YES')
