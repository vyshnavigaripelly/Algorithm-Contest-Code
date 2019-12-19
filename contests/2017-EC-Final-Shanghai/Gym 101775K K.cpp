#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long long arr[100007], sum[100007];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));
        long long a, b, n;
        scanf("%lld %lld %lld", &a, &b, &n);
        for (int i = 1; i <= a; i++)
        {
            scanf("%lld", &arr[i]);
            sum[i] = sum[i - 1] + arr[i];
        }
        long long aa = a, prea = -1, preb = -1;
        for (int i = 0; i < n; i++)
        {
            if (a == prea && b == preb)
            {
                break;
            }
            prea = a;
            preb = b;
            long long tmp = a;
            a = lower_bound(sum, sum + aa + 1, tmp) - sum;
            if (tmp == sum[a + 1])
            {
                a++;
            }
            b = tmp - sum[a - 1];
        }
        printf("Case #%d: %lld-%lld\n", cas, a, b);
    }
    return 0;
}