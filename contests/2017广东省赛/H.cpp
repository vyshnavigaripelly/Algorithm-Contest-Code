#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long k;
            scanf("%lld", &k);
            sum += k;
        }
        long long ans = m - (n * m - sum);
        printf("Case #%d: %lld\n", cas, max(ans, 0LL));
    }
    return 0;
}