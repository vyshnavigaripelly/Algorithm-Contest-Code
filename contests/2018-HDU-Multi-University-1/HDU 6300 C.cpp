#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int idx, x, y;
} arr[10007];

int cmp(const Node &a, const Node &b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 3 * n; i++)
        {
            scanf("%d %d", &arr[i].x, &arr[i].y);
            arr[i].idx = i;
        }
        sort(arr + 1, arr + 3 * n + 1, cmp);
        for (int i = 1; i <= 3 * n; i += 3)
        {
            printf("%d %d %d\n", arr[i].idx, arr[i + 1].idx, arr[i + 2].idx);
        }
    }
    return 0;
}