#include <bits/stdc++.h>

using namespace std;

const int S = 8;

long long mult_mod(long long a, long long b, long long c)
{
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;
    while (b)
    {
        if (b & 1)
        {
            ret += tmp;
            if (ret > c)
                ret -= c;
        }
        tmp <<= 1;
        if (tmp > c)
            tmp -= c;
        b >>= 1;
    }
    return ret;
}

long long pow_mod(long long a, long long n, long long mod)
{
    long long ret = 1;
    long long temp = a % mod;
    while (n)
    {
        if (n & 1)
            ret = mult_mod(ret, temp, mod);
        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }
    return ret;
}

bool check(long long a, long long n, long long x, long long t)
{
    long long ret = pow_mod(a, x, n);
    long long last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = mult_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1)
            return true;
        last = ret;
    }
    if (ret != 1)
        return true;
    else
        return false;
}

bool Miller_Rabin(long long n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;
    long long x = n - 1;
    long long t = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        t++;
    }
    srand(time(NULL));
    for (int i = 0; i < S; i++)
    {
        long long a = rand() % (n - 1) + 1;
        if (check(a, n, x, t))
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long x;
        scanf("%lld", &x);
        if (x < 12)
        {
            printf("Case %d: IMPOSSIBLE\n", cas);
        }
        else
        {
            if (x % 2 == 1)
            {
                printf("Case %d: 2 2 2 3 ", cas);
                x -= 9;
                for (long long k = x - 2;; k--)
                {
                    if (Miller_Rabin(k) && Miller_Rabin(x - k))
                    {
                        printf("%lld %lld\n", k, x - k);
                        break;
                    }
                }
            }
            else
            {
                printf("Case %d: 2 2 2 2 ", cas);
                x -= 8;
                for (long long k = x - 2;; k--)
                {
                    if (Miller_Rabin(k) && Miller_Rabin(x - k))
                    {
                        printf("%lld %lld\n", k, x - k);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}