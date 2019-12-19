#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

long long mod;
long long lenarr[50000], arr[50000];

long long qpow(long long x, long long n, long long mod = mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long x;
        scanf("%lld %lld", &x, &mod);
        arr[0] = 2 % mod;
        arr[1] = 10 % mod;
        if (lenarr[mod] == 0)
        {
            for (int i = 2;; i++)
            {
                arr[i] = (10 * arr[i - 1] - arr[i - 2] + mod) % mod;
                if (arr[i - 1] == arr[0] && arr[i] == arr[1])
                {
                    lenarr[mod] = i - 1;
                    break;
                }
            }
        }
        long long tmp = (1 + qpow(2, x, lenarr[mod])) % lenarr[mod];
        arr[0] = 2 % mod;
        arr[1] = 10 % mod;
        for (int i = 2; i <= tmp; i++)
        {
            arr[i] = (10 * arr[i - 1] - arr[i - 2] + mod) % mod;
        }
        printf("Case #%d: %lld\n", cas, (arr[tmp] - 1 + mod) % mod);
    }
    return 0;
}