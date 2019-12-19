#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
} arr[100007], tmp[100007];

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int cmpx(const Point &a, const Point &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int cmpy(const Point &a, const Point &b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

double solve(int l, int r)
{
    double d = 1e50;
    if (l == r)
    {
        return d;
    }
    if (r - l == 1)
    {
        return dist(arr[l], arr[r]);
    }
    int mid = (l + r) / 2;
    double dl = solve(l, mid), dr = solve(mid + 1, r);
    d = min(dl, dr);
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (fabs(arr[mid].x - arr[i].x) <= d)
        {
            tmp[cnt] = arr[i];
            cnt++;
        }
    }
    sort(tmp, tmp + cnt, cmpy);
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (tmp[j].y - tmp[i].y >= d)
            {
                break;
            }
            d = min(d, dist(tmp[i], tmp[j]));
        }
    }
    return d;
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr + n, cmpx);
        printf("%.2f\n", solve(0, n - 1) / 2);
    }
    return 0;
}