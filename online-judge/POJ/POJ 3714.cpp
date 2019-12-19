#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 2e5 + 7;
const double eps = 1e-8;
const double INF = 1e30;

struct Point
{
    double x, y;
    int c;
} p[MAXN], tmpt[MAXN];

double dist(Point a, Point b)
{
    if (a.c == b.c)
        return INF;
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

double solve(int left, int right)
{
    double d = INF;
    if (left == right)
        return d;
    if (left + 1 == right)
        return dist(p[left], p[right]);
    int mid = (left + right) / 2;
    double d1 = solve(left, mid), d2 = solve(mid + 1, right);
    d = min(d1, d2);
    int cnt = 0;
    for (int i = left; i <= right; i++)
    {
        if (fabs(p[mid].x - p[i].x) <= d)
            tmpt[cnt++] = p[i];
    }
    sort(tmpt, tmpt + cnt, cmpy);
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt && tmpt[j].y - tmpt[i].y < d; j++)
            d = min(d, dist(tmpt[i], tmpt[j]));
    }
    return d;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if (i < n)
            {
                p[i].c = 1;
            }
        }
        sort(p, p + 2 * n, cmpx);
        printf("%.3f\n", solve(0, 2 * n - 1));
    }
    return 0;
}