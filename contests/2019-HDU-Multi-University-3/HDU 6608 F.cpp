#include <bits/stdc++.h>

using namespace std;

const int S = 8;
long long mod;

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

__int128 fmul(__int128 a, __int128 b, __int128 mod = mod)
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

__int128 fpow(__int128 a, __int128 b, __int128 mod = mod)
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

__int128 inv(long long x)
{
    return fpow(x, mod - 2, mod);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        __int128 ans = 1;
        cin >> mod;
        for (long long i = mod - 2; i; i--)
        {
            if (Miller_Rabin(i))
            {
                cout << (long long)(ans % mod) << endl;
                break;
            }
            else
            {
                ans *= inv(i);
                ans %= mod;
            }
        }
    }
    return 0;
}
