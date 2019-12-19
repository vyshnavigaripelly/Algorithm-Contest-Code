#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Seg
{
    int l, r, idx;
} arr[300010];

int cmp(const Seg &a, const Seg &b)
{
    if (a.l != b.l)
    {
        return a.l < b.l;
    }
    else
    {
        return a.r > b.r;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &arr[i].l, &arr[i].r);
        arr[i].idx = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    int flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].l <= arr[i + 1].l && arr[i].r >= arr[i + 1].r)
        {
            printf("%d %d", arr[i + 1].idx, arr[i].idx);
            flag = 0;
            break;
        }
    }
    if (flag || n == 1)
    {
        printf("-1 -1");
    }
    return 0;
}
