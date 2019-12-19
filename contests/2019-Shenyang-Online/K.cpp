#include <iostream>

using namespace std;

const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;

long long a[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &k, &n);
        for (long long i = 1; i <= k; i++)
        {
            scanf("%lld", &a[i]);
            a[i] = (a[i] + a[i - 1]) % mod;
        }
        long long ed = 2 * k, x;
        for (long long i = k + 1; i <= ed; i++)
        {
            scanf("%lld", &x);
            a[i] = (x + a[i - 1]) % mod;
        }
        if (n <= ed)
        {
            printf("%lld\n", a[n]);
        }
        else
        {
            long long ans = (a[ed] + (n - ed) % mod * x) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}