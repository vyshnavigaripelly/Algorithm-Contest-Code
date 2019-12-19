#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long lowbit(long long x)
{
    return x & (-x);
}

long long sum(long long n)
{
    long long ans = 0;
    for (long long i = 1; i <= n; i <<= 1)
        ans += (n / i - n / (i << 1)) * i;
    return ans;
}

int main()
{
    long long n, m;
    while (~scanf("%lld%lld", &n, &m))
    {
        for (long long i = 1; i <= m; i++)
        {
            int q;
            scanf("%d", &q);
            if (q == 1)
            {
                long long tmp, tmp2;
                scanf("%lld%lld", &tmp, &tmp2);
                printf("%lld\n", sum(tmp2) - sum(tmp - 1));
            }
            else
            {
                long long tmp, ans = 0;
                scanf("%lld", &tmp);
                for (; tmp <= n; tmp += lowbit(tmp), ans++)
                    ;
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}