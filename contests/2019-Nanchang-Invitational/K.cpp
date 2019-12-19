#include <bits/stdc++.h>

using namespace std;

long long arr[100007], sum[100007], ans[100007];

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
            scanf("%lld", &arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            ans[i] = sum[r] - sum[l - 1];
        }
        sort(ans, ans + m);
        long long anss = 0;
        for (int i = 0; i < m; i++)
        {
            anss += ans[i] * (i + 1);
        }
        printf("%lld\n", anss);
    }
    return 0;
}