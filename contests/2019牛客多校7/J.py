t = int(input())
for cas in range(t):
    a, b = input().split()
    print(int(str(int(a[::-1]) + int(b[::-1]))[::-1]))
