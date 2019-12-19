#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100007;

int arr[maxn], dp[maxn], lpos[maxn], rpos[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int ans = arr[1], pos = 1;
        dp[1] = arr[1];
        lpos[1] = 1, rpos[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
            if (dp[i - 1] + arr[i] >= arr[i])
            {
                dp[i] = dp[i - 1] + arr[i];
                lpos[i] = lpos[i - 1];
                rpos[i] = i;
            }
            else
            {
                dp[i] = arr[i];
                lpos[i] = i;
                rpos[i] = i;
            }
            if (dp[i] > ans)
            {
                ans = dp[i];
                pos = i;
            }
        }
        printf("Case %d:\n", cas);
        printf("%d %d %d\n", ans, lpos[pos], rpos[pos]);
        if (cas != t)
        {
            printf("\n");
        }
    }
    return 0;
}