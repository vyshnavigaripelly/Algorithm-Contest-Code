#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5007;

int arr[maxn], tmp[maxn], brr[maxn];
long long sum;

void merge(int l, int r, int m)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (arr[i] > arr[j])
        {
            sum += m - i + 1;
            tmp[k++] = arr[j++];
        }
        else
        {
            tmp[k++] = arr[i++];
        }
    }
    while (i <= m)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = tmp[i];
}

void mergesort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, r, m);
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            brr[i] = arr[i];
        }
        mergesort(0, n - 1);
        long long ans = sum;
        for (int i = 0; i < n; i++)
        {
            sum += n - brr[i] * 2 - 1;
            ans = min(ans, sum);
        }
        printf("%lld\n", ans);
    }
    return 0;
}