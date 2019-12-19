try:
    input = raw_input
except:
    pass

for cas in range(int(input())):
    a, b = map(int, input().split())
    a -= 1
    flag1 = flag2 = 0
    if (a - 1) % 3 == 0:
        flag1 = 1
    if (b - 1) % 3 == 0:
        flag2 = 1
    print(abs(flag1 - flag2))