import re

try:
    input = raw_input
except:
    pass


def gcd(a, b):
    if not b:
        return a
    else:
        return gcd(b, a % b)


def tolist(s):
    polylist = [0] * 10
    s = '{' + s + '}'
    s = re.sub(r'([-+\{])(x)', r'\1 1\2', s)  # x -> 1x
    s = s.replace(' ', '')
    s = re.sub(r'(\d)(x)([-+\}])', r'\1\2^1\3', s)  # 4x -> 4x^1
    s = re.sub(r'([-+\{])(\d)([-+\}])', r'\1\2x^0\3', s)  # 4 -> 4x^0
    s = s[1:-1]
    s = re.split('x\^(\d)', s)
    for i in range(0, len(s) - 1, 2):
        polylist[int(s[i + 1])] += int(s[i])
    return polylist


def calc(poly, x):
    sum = 0
    for i in range(10):
        sum += poly[i] * x ** i
    return sum


def calcderivate(poly):
    ans = [0] * 10
    for i in range(0, 9):
        ans[i] = poly[i + 1] * (i + 1)
    return ans


for cas in range(int(input())):
    fenzi, fenmu = input(), input()
    x = int(input())
    fzlist = tolist(fenzi)
    fmlist = tolist(fenmu)
    fz = calc(fzlist, x)
    fm = calc(fmlist, x)
    while fm == 0 and fz == 0:
        fzlist = calcderivate(fzlist)
        fmlist = calcderivate(fmlist)
        fz = calc(fzlist, x)
        fm = calc(fmlist, x)
    if fz == 0:
        print(0)
    elif fm == 0:
        print('INF')
    else:
        k = gcd(fz, fm)
        fz /= k
        fm /= k
        if fm == 1:
            print(fz)
        else:
            print('%s%d/%d' % ('-' if fz * fm < 0 else '', abs(fz), abs(fm)))
