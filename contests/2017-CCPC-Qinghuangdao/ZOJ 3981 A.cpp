#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long pos[200007];
long long dd[200007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m, q, p, tim;
        long long ans = (long long)1e18, sum = 0;
        scanf("%lld%lld%lld", &n, &m, &q);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &pos[i]);
        }
        for (int i = 0; i < q; i++)
        {
            scanf("%lld%lld", &p, &tim);
            dd[i] = (pos[p - 1] - 1 - tim % m + m) % m;
            sum += dd[i];
        }
        sort(dd, dd + q);
        for (int i = 0; i < q; i++)
        {
            if (i == 0 || dd[i] != dd[i - 1])
                ans = min(ans, sum + (i)*m - q * dd[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}