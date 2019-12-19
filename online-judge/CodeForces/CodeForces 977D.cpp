#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[200], n;
long long arr[200], ans[200];

void dfs(int idx, int step)
{
    if (step == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        return;
    }
    long long next;
    int nextidx;
    next = arr[idx] * 2;
    nextidx = find(arr, arr + n, next) - arr;
    if (nextidx != n && vis[nextidx] == 0)
    {
        vis[nextidx] = step;
        ans[step] = next;
        dfs(nextidx, step + 1);
        vis[nextidx] = 0;
    }
    next = arr[idx] / 3;
    nextidx = find(arr, arr + n, next) - arr;
    if (arr[idx] % 3 == 0 && nextidx != n && vis[nextidx] == 0)
    {
        vis[nextidx] = step;
        ans[step] = next;
        dfs(nextidx, step + 1);
        vis[nextidx] = 0;
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ans[0] = arr[i];
        dfs(i, 1);
    }
    return 0;
}
