#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const long long mod = 1e9 + 7;

long long mi[68] = {1, 2};

long long lowbitcnt(long long n)
{
    long long ans = 0;
    while (n % 2 == 0)
    {
        ans++;
        n /= 2;
    }
    return ans + 1;
}

long long qpow(long long a, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans % mod;
}

int main()
{
    long long inv2 = qpow(2, mod - 2);
    for (int i = 1; i < 63; i++)
    {
        mi[i] = mi[i - 1] << 1;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (n == 1)
        {
            puts("1");
            continue;
        }
        n++;
        long long l = max(1LL, n / 2 - 50), r = min(n, n / 2 + 50);
        long long head, tail, N;
        while (l <= r)
        {
            long long m = (l + r) / 2;
            long long cnt = 2, d = 2;
            for (int i = 1; mi[i - 1] <= m; i++)
            {
                cnt += ((m - mi[i - 1]) / d + 1) * i;
                d *= 2;
            }
            tail = cnt;
            head = cnt - lowbitcnt(m) + 1;
            if (head <= n && tail >= n)
            {
                N = m;
                break;
            }
            else if (n >= head)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        // cout << N << endl;
        // n 1 2 3 4 5 6 7 8 9 10 11 12
        // N 1 1 2 2 3 4 4 4 5 6  6  7
        // int maxpos = lower_bound(mi, mi + 63, N) - mi;
        long long ans = 1;
        for (int i = 1; mi[i - 1] <= N - 1; i++)
        {
            long long first = mi[i - 1];
            long long d = mi[i];
            long long num = ((N - 1 - first) / d + 1) % mod;
            // cout << num << endl;
            long long delta = (first % mod * num % mod + (num - 1 + mod) % mod * num % mod * (d % mod) % mod * inv2 % mod) % mod;
            ans = (ans % mod + i * delta % mod) % mod;
        }
        ans = (ans + (n - head + 1) * N % mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}