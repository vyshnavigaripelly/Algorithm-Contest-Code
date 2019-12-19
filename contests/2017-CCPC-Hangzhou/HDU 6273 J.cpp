#include <iostream>
#include <cstring>

using namespace std;

const int N = 100007, INF = 1 << 30, mod = 998244353;

int two[N], three[N];

long long qpow(long long a, long long b, long long m = mod)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
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
        memset(two, 0, sizeof(two));
        memset(three, 0, sizeof(three));
        while (m--)
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            (x == 2 ? two : three)[l]++;
            (x == 2 ? two : three)[r + 1]--;
        }
        int twomin = INF, threemin = INF;
        for (int i = 1; i <= n; i++)
        {
            two[i] += two[i - 1];
            three[i] += three[i - 1];
            twomin = min(twomin, two[i]);
            threemin = min(threemin, three[i]);
        }
        long long ans = qpow(2, twomin) * qpow(3, threemin) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}