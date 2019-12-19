#include <iostream>

using namespace std;

const int N = 1e5 + 7, mod = (int)1e9 + 7;

long long table[N];

long long qpow(long long a, long long b, long long m = mod)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

void maketable()
{
    long long presum = 0, ans = 0;
    for (int i = 3; i < N; i++)
    {
        presum = (presum + 1LL * (i - 2 + 1) * (i - 2) / 2 + mod) % mod;
        ans = (ans + presum + mod) % mod;
        table[i] = ans;
    }
}

int main()
{
    maketable();
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("Case %d: %lld\n", cas, table[n] * table[m] % mod);
    }
    return 0;
}