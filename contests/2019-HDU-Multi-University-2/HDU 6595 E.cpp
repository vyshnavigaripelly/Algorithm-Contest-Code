#include <iostream>

using namespace std;

const int mod = 998244353;

long long qpow(long long x, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}

long long inv(long long x)
{
    return qpow(x, mod - 2);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        long long a = 0, b = 3 * n;
        for (int i = 0; i < n; i++)
        {
            a += i * (i + 1);
        }
        printf("%lld\n", a * inv(b) % mod);
    }
    return 0;
}