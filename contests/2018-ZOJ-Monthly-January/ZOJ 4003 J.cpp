#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long arr[1007], brr[1007], dist[1007][1007];

long long pow_m(int x, int y)
{
    long long ans = 1;
    if (x < 0)
        x = -x;
    for (int i = 1; i <= y; i++)
    {
        ans *= x;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, v, q;
        scanf("%lld %lld %lld", &n, &v, &q);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &brr[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                dist[i][j] = pow_m(arr[i] - brr[j], q);
        }
        long long crr[3007] = {0}, val[3007] = {0};
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int temp = i - j + n;
                crr[temp]++;
                val[temp] += dist[i][j];
                while (crr[temp] > 0 && val[temp] > v)
                {
                    crr[temp]--, val[temp] -= dist[i - crr[temp]][j - crr[temp]];
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}