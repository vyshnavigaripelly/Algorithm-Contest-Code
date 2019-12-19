#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 2e5 + 7;

struct Point
{
    long long x, y, idx;
} arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
        arr[i].idx = i + 1;
    }
    sort(arr, arr + n, [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    int flag = 1;
    for (int i = 2; i < n; i++)
    {
        if ((arr[i].y - arr[i - 1].y) * (arr[i - 1].x - arr[i - 2].x) != (arr[i].x - arr[i - 1].x) * (arr[i - 1].y - arr[i - 2].y))
        {
            flag = 0;
        }
    }
    if (flag)
    {
        puts("1");
        printf("%lld %lld\n", arr[0].idx, arr[n - 1].idx);
    }
    else
    {
        puts("0");
    }
    return 0;
}