input = raw_input

def sqrt2(n):
    nstr = str(n)
    ans = int(nstr[0:len(nstr) // 2 + 1])
    while n < ans * ans:
        ans = (ans + (n // ans)) // 2
    return ans

for cas in range(int(input())):
    n = int(input())
    tmp = sqrt2(n)
    print(0 if (tmp % 2) == 0 else 1)
