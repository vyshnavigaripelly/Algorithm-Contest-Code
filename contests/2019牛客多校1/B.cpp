#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

long long arr[1007];

long long fpow(long long a, long long b, long long mod = mod)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

long long inv(long long x, long long mod = mod)
{
    return fpow(x, mod - 2, mod);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        __int128 ans = 0;
        for (int i = 0; i < n; i++)
        {
            __int128 tmp = 2 * arr[i], sgn = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                tmp *= arr[i] * arr[i] - arr[j] * arr[j];
                if (tmp < 0)
                {
                    sgn *= -1;
                    tmp = -tmp;
                }
                tmp %= mod;
            }
            if (n % 2 == 0)
            {
                tmp *= -1;
            }
            if (tmp < 0)
            {
                tmp = -tmp;
                sgn *= -1;
            }
            ans += sgn * inv(tmp);
            ans = (ans % mod + mod) % mod;
        }
        printf("%lld\n", (long long)ans);
    }
    return 0;
}