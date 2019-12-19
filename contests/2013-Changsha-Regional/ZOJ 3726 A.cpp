#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const long long INF = 1LL << 62;

long long s[N], p[N], w[N];

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
            scanf("%lld %lld", &s[i], &p[i]);
            w[i] = s[i] * p[i];
        }
        s[n + 1] = INF;
        p[n + 1] = p[n];
        w[n + 1] = INF;
        for (int i = n - 1; i >= 1; i--)
        {
            w[i] = min(w[i], w[i + 1]);
        }
        while (m--)
        {
            int k;
            scanf("%d", &k);
            int pos = lower_bound(s + 1, s + 1 + n + 1, k) - s;
            long long ans = min(k * p[pos - 1], w[pos]);
            printf("%lld\n", ans);
        }
    }
    return 0;
}