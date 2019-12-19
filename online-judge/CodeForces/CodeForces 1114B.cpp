#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

long long arr[200007], brr[200007];

map<long long, int> mp;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        brr[i] = arr[i];
    }
    sort(brr + 1, brr + 1 + n, greater<long long>());
    for (int i = 1; i <= m * k; i++)
    {
        mp[brr[i]]++;
    }
    long long ans = accumulate(brr + 1, brr + 1 + m * k, 0LL);
    printf("%lld\n", ans);
    int tmp = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[arr[i]] > 0)
        {
            tmp++;
            mp[arr[i]]--;
        }
        if (tmp == m)
        {
            cnt++;
            if (cnt == k)
            {
                break;
            }
            printf("%d ", i);
            tmp = 0;
        }
    }
    return 0;
}