#include <iostream>
#include <cstdio>

using namespace std;

long long q, k, mod;

long long qpow(long long a, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return s % mod;
}

long long sum(long long q, long long n)
{
    if (n == 1)
        return q;
    long long tmp = sum(q, n / 2);
    long long ans = tmp + tmp * qpow(q, n / 2);
    if (n % 2 == 1)
        ans += qpow(q, n);
    return ans % mod;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld %lld", &q, &k, &mod);
        printf("%lld\n", sum(q, k));
    }
    return 0;
}