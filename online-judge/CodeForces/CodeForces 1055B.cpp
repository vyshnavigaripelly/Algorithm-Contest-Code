#include <iostream>
#include <cstdio>
using namespace std;

long long flag[100007], arr[100007];

int main()
{
    long long n, m, l, ans = 0;
    scanf("%lld %lld %lld", &n, &m, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] > l)
        {
            flag[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] && !flag[i - 1])
        {
            ans++;
        }
    }
    while (m--)
    {
        long long q, a, b;
        scanf("%lld", &q);
        if (q == 0)
        {
            printf("%lld\n", ans);
        }
        else if (q == 1)
        {
            scanf("%lld %lld", &a, &b);
            arr[a] += b;
            if (!flag[a] && arr[a] > l)
            {
                flag[a] = 1;
                if (flag[a - 1] && a < n && flag[a + 1])
                {
                    ans--;
                }
                else if (!flag[a - 1])
                {
                    if (a != n && flag[a + 1])
                    {
                        continue;
                    }
                    ans++;
                }
            }
        }
    }
    return 0;
}