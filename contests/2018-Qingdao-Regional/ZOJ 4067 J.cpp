#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int cnt = 0, n, m, minn = 0x3f3f3f3f;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0)
            {
                cnt++;
            }
            minn = min(minn, arr[i]);
        }
        if (cnt > m)
        {
            puts("Impossible");
        }
        else if (n == m)
        {
            puts("Richman");
        }
        else if (m == 0)
        {
            printf("%d\n", minn - 1);
        }
        else
        {
            long long ans = 0;
            minn = 0x3f3f3f3f;
            if (cnt != 0)
            {
                m -= cnt;
                int tmp = 0, pos = 0;
                while (pos < n && tmp < m)
                {
                    if (arr[pos] == 0)
                    {
                        pos++;
                        continue;
                    }
                    tmp++;
                    ans += arr[pos++];
                }
                for (int i = pos; i < n; i++)
                {
                    if (arr[i] == 0)
                    {
                        continue;
                    }
                    minn = min(minn, arr[i]);
                }
                printf("%lld\n", ans + minn - 1);
            }
            else
            {
                for (int i = 0; i < m; i++)
                {
                    ans += arr[i];
                }
                for (int i = m; i < n; i++)
                {
                    minn = min(minn, arr[i]);
                }
                ans += minn;
                printf("%lld\n", ans - 1);
            }
        }
    }
    return 0;
}