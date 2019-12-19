#include <iostream>
#include <algorithm>

using namespace std;

long long sum1[100], sum2[100];
long long s1[100007], s2[100007], x1[100007][6], x2[100007][6], n, m, k;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld", &n, &m, &k);
        long long tar = (1 << k) - 1, now;
        for (int i = 0; i <= tar + 1; i++)
        {
            sum1[i] = sum2[i] = -0x3f3f3f3f3f3f3f3f;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &s1[i]);
            for (int j = 0; j < k; j++)
                scanf("%lld", &x1[i][j]);
            for (now = tar; now >= 0; now--)
            {
                long long tmp = s1[i];
                for (int j = 0; j < k; j++)
                {
                    if (now >> j & 1)
                        tmp += x1[i][j];
                    else
                        tmp -= x1[i][j];
                }
                sum1[now] = max(sum1[now], tmp);
            }
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &s2[i]);
            for (int j = 0; j < k; j++)
                scanf("%lld", &x2[i][j]);
            for (now = tar; now >= 0; now--)
            {
                long long tmp = s2[i];
                for (int j = 0; j < k; j++)
                {
                    if (now >> j & 1)
                        tmp += x2[i][j];
                    else
                        tmp -= x2[i][j];
                }
                sum2[now] = max(sum2[now], tmp);
            }
        }
        long long ans = -0x3f3f3f3f3f3f3f3f;
        for (now = tar; now >= 0; now--)
        {
            long long fnow = 0;
            //cout << ~now << "fymsb" << endl;
            for (int i = 0; i < k; i++)
            {
                if (now >> i & 1)
                    continue;
                fnow |= (1 << i);
            }
            ans = max(sum1[now] + sum2[fnow], ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
