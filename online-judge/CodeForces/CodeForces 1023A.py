n, m = map(int, input().split())
s = input()
t = input()
if '*' in s:
    x, y = s.split('*')
    if t.startswith(x) and t[len(x):].endswith(y):
        print('YES')
    else:
        print('NO')
else:
    print('YES' if s == t else 'NO')
