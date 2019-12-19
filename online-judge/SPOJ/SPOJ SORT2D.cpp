#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
} arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr + n, [](const Node &a, const Node &b) {
            return a.x < b.x || (a.x == b.x && a.y > b.y);
        });
        for (int i = 0; i < n; i++)
        {
            printf("%d %d\n", arr[i].x, arr[i].y);
        }
    }
    return 0;
}