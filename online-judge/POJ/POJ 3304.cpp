#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-10;

int n;

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) { x = xx, y = yy; }

    bool operator==(Point b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
} p[207];

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    // 直线和线段相交判断 {2:规范相交, 1:非规范相交, 0:不相交}
    int linecrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2)
            return 2;
        return (d1 == 0 || d2 == 0);
    }
} arr[107];

int check(Point a, Point b)
{
    if (a == b)
    {
        return 0;
    }
    Line line = Line(a, b);
    for (int i = 0; i < n; i++)
    {
        if (line.linecrossseg(arr[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            double sx, sy, ex, ey;
            scanf("%lf %lf %lf %lf", &sx, &sy, &ex, &ey);
            p[i * 2] = Point(sx, sy);
            p[i * 2 + 1] = Point(ex, ey);
            arr[i] = Line(p[i * 2], p[i * 2 + 1]);
        }
        int flag = 0;
        for (int i = 0; i < 2 * n && !flag; i++)
        {
            for (int j = i + 1; j < 2 * n && !flag; j++)
            {
                if (check(p[i], p[j]))
                {
                    flag = 1;
                }
            }
        }
        puts(flag ? "Yes!" : "No!");
    }
    return 0;
}