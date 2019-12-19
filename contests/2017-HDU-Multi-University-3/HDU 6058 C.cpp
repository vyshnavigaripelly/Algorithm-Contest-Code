#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e5 + 7,
          INF = (1 << 30);

long long arr[N], l[N], r[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        arr[0] = arr[n + 1] = INF;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int cntl = 0, cntr = 0;
            for (int j = i + 1; j <= n + 1; j++)
            {
                if (cntr >= k)
                {
                    break;
                }
                if (arr[j] > arr[i])
                {
                    r[++cntr] = j - i;
                }
            }
            for (int j = i - 1; j >= 0; j--)
            {
                if (cntl >= k)
                {
                    break;
                }
                if (arr[j] > arr[i])
                {
                    l[++cntl] = i - j;
                }
            }
            if (cntl + cntr + 1 < k)
            {
                continue;
            }
            for (int j = 1; j <= cntl; j++)
            {
                if (j + cntr <= k)
                {
                    continue;
                }
                ans += 1LL * arr[i] * (l[j] - l[j - 1]) * (r[k - j + 1] - r[k - j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}