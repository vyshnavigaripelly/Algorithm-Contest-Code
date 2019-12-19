#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int arr[N], brr[N], vis[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &brr[i]);
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (vis[brr[i]])
            continue;
        printf("%d ", brr[i]);
        vis[brr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}