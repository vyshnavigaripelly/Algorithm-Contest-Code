#include <iostream>
#include <cstdio>

using namespace std;

long long fpow(long long a, long long n, long long mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return s;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long mod, n;
        scanf("%lld %lld", &mod, &n);
        long long ans = 0;
        while (n--)
        {
            long long a, b;
            scanf("%lld %lld", &a, &b);
            ans = (ans + fpow(a, b, mod)) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}