#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 7;

int arr[N], brr[N], hs[N], c[N], id[N], l[N], r[N], n;

int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += c[x];
        x -= (x & -x);
    }
    return ans;
}

void add(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += (x & -x);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &arr[i], &brr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        id[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        hs[i] = id[brr[i]];
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i >= 1; i--)
    {
        r[i] = query(hs[i] - 1);
        add(hs[i], 1);
    }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        l[i] = i - 1 - query(hs[i] - 1);
        add(hs[i], 1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", l[i] + r[i]);
    }
    return 0;
}