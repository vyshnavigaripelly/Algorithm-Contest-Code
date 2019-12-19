#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5 + 7;
const int mod = 998244353;

long long arr[N];

long long qpow(long long a, long long b = mod - 2, long long m = mod)
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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            arr[i] += arr[i - 1];
        }
        for (int i = 0; i < m; i++)
        {
            int op, l, r;
            scanf("%d %d %d", &op, &l, &r);
            if (op == 2)
            {
                long long w = ((arr[r] - arr[l - 1]) % mod + mod) % mod;
                printf("%lld\n", w * qpow(2, 1LL * m * n) % mod);
            }
        }
    }
    return 0;
};
