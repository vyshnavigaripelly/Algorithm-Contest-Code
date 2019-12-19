#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long mod = 998244353;
const long long N = 1e5 + 7;

long long fac[N + 5], inv[N + 5];

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
    return s % mod;
}

void init()
{
    fac[0] = 1;
    for (long long i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[N] = qpow(fac[N], mod - 2);
    for (long long i = N - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

long long C(long long n, long long m)
{
    if (m > n)
        return 0;
    if (m == n || m == 0)
        return 1;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void table(int maxn)
{
    for (int n = 1; n <= maxn; n++)
    {
        vector<int> a;
        for (int i = 0; i < n; i++)
            a.push_back(i);
        int cnt = 0;
        do
        {
            int flag = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((a[(i + j) % n] + 1) % n == a[(i + j + 1) % n])
                        flag = 0;
                }
                if (flag == 1)
                    cnt++;
            }
        } while (next_permutation(a.begin(), a.end()));
        cout << cnt / n / n << endl;
    }
}

int main()
{
    // 0 0 1 1 8 36 229 1625 13208 120288
    // A000757 - a(n) = (-1)^n + sum[k=0, n-1]((-1)^k * binomial(n, k) * (n-k-1)!)
    init();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long ans = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            ans = (ans + ((i % 2 == 1) ? -1 : 1) * C(n, i) * fac[n - i - 1] % mod) % mod;
        }
        ans += ((n % 2 == 1) ? -1 : 1);
        printf("%lld\n", (ans + mod) % mod);
    }
    return 0;
}
