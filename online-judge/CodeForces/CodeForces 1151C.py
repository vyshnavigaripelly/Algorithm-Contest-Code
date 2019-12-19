powsum = [0] * 80


def find(n):
    l, r = 0, 79
    while l < r:
        mid = (l + r + 1) // 2
        if powsum[mid] > n:
            r = mid - 1
        else:
            l = mid
    return l


def calc(n):
    posn = find(n)
    if posn % 2 == 0:
        pos = posn // 2
        q = 4

        first1 = 2
        last1 = 2 * 2 * (1 - q ** pos) // (1 - q)
        num1 = 2 * (1 - q ** pos) // (1 - q)
        sum1 = (first1 + last1) * num1 // 2

        first2 = 1
        last2 = ((1 - q ** pos) // (1 - q) - 1) * 2 + 1
        num2 = (1 - q ** pos) // (1 - q)
        sum2 = (first2 + last2) * num2 // 2

        first3 = 2 * ((1 - q ** pos) // (1 - q)) + 1
        last3 = first3 + (n - powsum[posn] - 1) * 2
        num3 = n - powsum[posn]
        sum3 = (first3 + last3) * num3 // 2
    else:
        pos1 = posn // 2
        pos2 = (posn + 1) // 2
        q = 4

        first1 = 2
        last1 = 2 * 2 * (1 - q ** pos1) // (1 - q)
        num1 = 2 * (1 - q ** pos1) // (1 - q)
        sum1 = (first1 + last1) * num1 // 2

        first2 = 1
        last2 = 1 + ((1 - q ** pos2) // (1 - q) - 1) * 2
        num2 = (1 - q ** pos2) // (1 - q)
        sum2 = (first2 + last2) * num2 // 2

        first3 = 4 * ((1 - q ** pos1) // (1 - q)) + 2
        last3 = first3 + (n - powsum[posn] - 1) * 2
        num3 = n - powsum[posn]
        sum3 = (first3 + last3) * num3 // 2
    return sum1 + sum2 + sum3


l, r = map(int, input().split())
for i in range(1, 80):
    powsum[i] = powsum[i - 1] + 2 ** (i - 1)
print((calc(r) - calc(l - 1)) % int(1e9 + 7))
