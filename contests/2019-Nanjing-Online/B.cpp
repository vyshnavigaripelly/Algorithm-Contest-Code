#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long m, a, b;

__int128 euler(__int128 n)
{
    __int128 res = n, a = n;
    for (__int128 i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            res = res / i * (i - 1);
            while (a % i == 0)
                a /= i;
        }
    }
    if (a > 1)
        res = res / a * (a - 1);
    return res;
}

__int128 fmul(__int128 a, __int128 b, __int128 mod)
{
    __int128 ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}

__int128 fpow(__int128 a, __int128 b, __int128 mod)
{
    __int128 ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = fmul(ans, a, mod);
        a = fmul(a, a, mod);
        b >>= 1;
    }
    return ans;
}

__int128 func(__int128 cnt, __int128 m)
{
    if (m == 1)
        return 0;
    __int128 phi = euler(m), ans = 1;
    if (cnt == 1 || (a == 2 && cnt <= 4) || (a >= 3 && a <= 7 && cnt <= 2))
    {
        __int128 ans = 1;
        for (int i = 1; i <= cnt; i++)
            ans = fpow(a, ans, 1e30);
        if (ans <= phi)
        {
            return ans;
        }
        ans = 1;
        for (int i = 1; i <= cnt; i++)
            ans = fpow(a, ans, m);
        __int128 z = func(cnt - 1, phi);
        ans = fpow(a, phi + z, m);
        return ans;
    }
    else
    {
        __int128 z = func(cnt - 1, phi);
        ans = fpow(a, phi + z, m);
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld %lld", &a, &b, &m);
        if (a == 1 || b == 0)
        {
            printf("%lld\n", 1 % m);
            continue;
        }
        if (b == 1)
        {
            printf("%lld\n", a % m);
            continue;
        }
        if (b == 2)
        {
            printf("%lld\n", (long long)fpow(a, a, m));
            continue;
        }
        printf("%lld\n", (long long)func(b, m) % m);
    }
    return 0;
}