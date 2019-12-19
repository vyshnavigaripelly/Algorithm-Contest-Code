#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
    string id;
} arr[1000007];

string dfs(int x, int y, long long s, int d)
{
    long long mid = s / 2;
    string ans;
    if (d >= 1)
    {
        if (x <= mid && y <= mid)
            ans = "1" + dfs(y, x, mid, d - 1);
        else if (x > mid && y <= mid)
            ans = "2" + dfs(x - mid, y, mid, d - 1);
        else if (x > mid && y > mid)
            ans = "3" + dfs(x - mid, y - mid, mid, d - 1);
        else if (x <= mid && y > mid)
            ans = "4" + dfs(s - y + 1, mid - x + 1, mid, d - 1);
    }
    return ans;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        arr[i].id = dfs(arr[i].x, arr[i].y, 1LL << k, k);
    }
    sort(arr, arr + n, [](const Node &a, const Node &b) {
        return a.id < b.id;
    });
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    return 0;
}