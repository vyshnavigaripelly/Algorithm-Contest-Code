#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100007;

long long ans;
int a[MAXN], b[MAXN], c[MAXN];

void merge(int a[], int left, int mid, int right)
{
    int i, j;
    i = 0;
    for (j = left; j <= mid; j++)
        b[i++] = a[j];
    int len1 = mid - left + 1;
    i = 0;
    for (j = mid + 1; j <= right; j++)
        c[i++] = a[j];
    int len2 = right - mid;
    i = j = 0;
    int k = left;
    while (i < len1 && j < len2 && k <= right)
    {
        if (b[i] <= c[j])
            a[k++] = b[i++];
        else
        {
            a[k++] = c[j++];
            ans += (len1 - i);
        }
    }
    while (i < len1)
        a[k++] = b[i++];
    while (j < len2)
        a[k++] = c[j++];
}

void merge_sort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int n, x, y;
    while (~scanf("%d %d %d", &n, &x, &y))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        ans = 0;
        merge_sort(a, 0, n - 1);
        printf("%lld\n", ans * min(x, y));
    }
    return 0;
}