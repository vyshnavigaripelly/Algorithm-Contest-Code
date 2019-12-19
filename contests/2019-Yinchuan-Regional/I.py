import string

s = string.digits + string.ascii_uppercase + string.ascii_lowercase

x, y, z = input().split()
x, y = map(int, (x, y))
z = z[::-1]

tmp = 0
for i in range(len(z)):
    tmp += s.index(z[i]) * x ** i

ans = ''
while tmp > 0:
    ans += s[tmp % y]
    tmp //= y

print(ans[::-1] if ans else '0')
