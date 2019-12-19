#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10007;

int arr[maxn], dp[maxn], lpos[maxn], rpos[maxn];

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        int negative = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] >= 0)
            {
                negative = 0;
            }
        }
        if (negative)
        {
            printf("%d %d %d\n", 0, arr[1], arr[n]);
        }
        else
        {
            int ans = arr[1], pos = 1;
            dp[1] = arr[1];
            lpos[1] = 1, rpos[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                if (dp[i - 1] + arr[i] > arr[i])
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
            printf("%d %d %d\n", ans, arr[lpos[pos]], arr[rpos[pos]]);
        }
    }
    return 0;
}