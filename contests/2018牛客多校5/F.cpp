#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const int mod = 998244353;

struct Node
{
    long long p, d, id;
} arr[N];

struct BIT
{
    long long c[N];

    void init()
    {
        for (int i = 0; i < N; i++)
            c[i] = 1;
    }

    void add(int pos, long long val)
    {
        while (pos <= N)
        {
            c[pos] = c[pos] * val % mod;
            pos += pos & -pos;
        }
    }

    long long query(int l, int r)
    {
        return l > r ? 0 : presum(r) - presum(l - 1);
    }

    long long presum(int pos)
    {
        long long ans = 1;
        while (pos > 0)
        {
            ans = ans * c[pos] % mod;
            pos -= pos & -pos;
        }
        return ans;
    }
} bit;

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
    long long inv100 = qpow(100);
    int n;
    scanf("%d", &n);
    bit.init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &arr[i].p, &arr[i].d);
        arr[i].id = i;
    }
    sort(arr + 1, arr + 1 + n, [](const Node &a, const Node &b) {
        return a.d > b.d || (a.d == b.d && a.id < b.id);
    });
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long sum = bit.presum(arr[i].id - 1) * arr[i].p % mod * inv100 % mod;
        ans = (ans + sum) % mod;
        bit.add(arr[i].id, (100 - arr[i].p) * inv100 % mod);
    }
    printf("%lld\n", ans);
    return 0;
}