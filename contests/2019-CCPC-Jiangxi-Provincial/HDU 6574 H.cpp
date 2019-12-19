#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
const int mod = 1e9 + 7;

__int128 presum[N], inv[N];

void initinv()
{
    inv[1] = presum[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        presum[i] = (presum[i - 1] + inv[i]) % mod;
    }
}

__int128 qpow(__int128 a, __int128 b = mod - 2)
{
    __int128 res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    initinv();
    int n;
    scanf("%d", &n);
    __int128 p = 0, q = n * n % mod;
    for (int i = 1; i <= n; i++)
    {
        p = (p + i * (presum[n] - presum[i] + mod) % mod) % mod;
    }
    p = (p + n * qpow(2) % mod + n * (1 + n) % mod * qpow(4) % mod) % mod;
    __int128 ans = p * qpow(q) % mod;

    printf("%lld\n", (long long)ans);
    return 0;
}