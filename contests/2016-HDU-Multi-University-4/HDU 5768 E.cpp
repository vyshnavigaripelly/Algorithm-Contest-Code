#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

long long a[N], b[N], p[N], r[N];

__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    __int128 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

__int128 CRT(long long p[], long long r[], int len)
{
    __int128 n = 1, sum = 0, x, y;
    for (int i = 0; i < len; i++)
    {
        n *= p[i];
    }
    for (int i = 0; i < len; i++)
    {
        __int128 m = n / p[i];
        exgcd(p[i], m, x, y);
        sum = (sum + y * m * r[i]) % n;
    }
    return (n + sum % n) % n;
}

long long solve(long long l, long long r, long long k, long long d)
{
    if (d > r)
        return 0;
    long long sum = max(0LL, (r - d) / k) - max(0LL, (l - d) / k);
    if ((l <= d && r >= d) || (l - d) % k == 0)
        sum++;
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        long long x, y;
        scanf("%d %lld %lld", &n, &x, &y);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &a[i], &b[i]);
        }
        __int128 sum = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            int len = 1;
            p[0] = 7;
            r[0] = 0;
            __int128 mul = 7;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    p[len] = a[j];
                    r[len] = b[j];
                    mul *= p[len];
                    len++;
                }
            }
            __int128 d = CRT(p, r, len), tmp = solve(x, y, mul, d);
            sum += ((len - 1) % 2 == 0 ? 1 : -1) * tmp;
        }
        printf("Case #%d: %lld\n", cas, (long long)sum);
    }
    return 0;
}