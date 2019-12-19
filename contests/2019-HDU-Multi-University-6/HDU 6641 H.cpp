#include <bits/stdc++.h>

using namespace std;

long long pd(long long x, int num)
{
    int cnt = 0;
    for (long long i = x + 1;; i++)
    {
        if (__gcd(i, x) == 1)
            cnt++;
        if (num == cnt)
            return i;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long k;
        int m, flag = 1;
        scanf("%lld %d", &k, &m);
        long long l = max(k - 1000, 1ll);
        long long r = k + 1000;
        for (long long i = l; i <= r; i++)
        {
            long long ans = pd(i, m);
            ans -= i;
            ans ^= i;
            if (ans == k)
            {
                printf("%lld\n", i);
                flag = 0;
                break;
            }
        }
        if (flag)
            puts("-1");
    }
    return 0;
}