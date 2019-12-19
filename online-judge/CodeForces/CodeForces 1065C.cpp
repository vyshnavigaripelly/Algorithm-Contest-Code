#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[200007], diff[200007];

int main()
{
    long long n, k, maxn = 0, minn = 3e5;
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        maxn = max(maxn, arr[i]);
        minn = min(minn, arr[i]);
        diff[arr[i]]++;
    }
    long long cnt = 0;
    for (long long i = maxn - 1; i >= minn; i--)
    {
        diff[i] += diff[i + 1];
    }
    long long tmp = 0;
    long long h = maxn;
    if (maxn == minn)
    {
        puts("0");
        return 0;
    }
    while (h > minn)
    {
        if (tmp + diff[h] <= k)
        {
            tmp += diff[h];
            h--;
        }
        else
        {
            tmp = 0;
            cnt++;
        }
    }
    cnt++;
    printf("%lld\n", cnt);
    return 0;
}