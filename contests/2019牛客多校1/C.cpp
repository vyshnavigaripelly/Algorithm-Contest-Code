#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1007];

int main()
{
    long long n, m;
    while (~scanf("%lld %lld", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr + 1, arr + 1 + n, greater<int>());
        long long rest = m, cur = 1;
        while (cur < n)
        {
            if (rest < (arr[cur] - arr[cur + 1]) * cur)
            {
                break;
            }
            rest -= (arr[cur] - arr[cur + 1]) * cur;
            cur++;
        }
        long long ans = (arr[cur] * cur - rest) * (arr[cur] * cur - rest) * cur;
        long long fenmu = m * m * cur * cur;
        for (int i = cur + 1; i <= n; i++)
        {
            ans += arr[i] * arr[i] * cur * cur;
        }
        long long g = __gcd(ans, fenmu);
        if (ans % fenmu == 0)
        {
            printf("%lld\n", ans / fenmu);
        }
        else
        {
            printf("%lld/%lld\n", ans / g, fenmu / g);
        }
    }
    return 0;
}