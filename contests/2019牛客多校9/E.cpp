#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int bcj[N];

int Find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = Find(bcj[x]);
}

void print(__int128 x)
{
    if (x < 0)
    {
        x = -x;
        putchar('-');
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

__int128 c4(__int128 n)
{
    return (n * (n - 1) * (n - 2) * (n - 3)) / (4 * 3 * 2);
}

__int128 c2(__int128 n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(bcj, -1, sizeof(bcj));
    print(c4(n));
    printf("\n");
    __int128 ans = c4(n);
    int cnt = n;
    __int128 res = 0;
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (n < 4)
        {
            printf("0\n");
            continue;
        }
        int X = Find(x), Y = Find(y);
        if (X != Y)
        {
            res -= (c2(-bcj[X]) + c2(-bcj[Y]));
            __int128 change = -bcj[X] * -bcj[Y] * (c2(cnt - (-bcj[X] + -bcj[Y])) - res);
            ans -= change;
            bcj[X] += bcj[Y];
            res += c2(-bcj[X]);
            bcj[Y] = X;
            n--;
        }
        print(ans);
        printf("\n");
    }
    return 0;
}