#include <bits/stdc++.h>

using namespace std;

long long arr[500007], sub[500007];

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (long long i = 2; i <= n; i++)
    {
        sub[i] = arr[i] - arr[i - 1];
    }
    long long ans = 0;
    for (long long i = 2; i <= n; i++)
    {
        if (sub[i] > 0)
        {
            ans += sub[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
