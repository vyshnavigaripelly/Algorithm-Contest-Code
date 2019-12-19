#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const int maxp = 107;

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
    bool operator<(Point b) const { return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const double &k) const { return Point(x * k, y * k); }
    Point operator/(const double &k) const { return Point(x / k, y / k); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    double distance(Point p) { return hypot(x - p.x, y - p.y); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    bool operator==(Line v) { return (s == v.s) && (e == v.e); }

    // 两线段相交判断 {2:规范相交, 1:非规范相交, 0:不相交}
    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
};

struct Polygon
{
    int n;
    Point p[maxp];
    Line l[maxp];

    void add(Point q)
    {
        p[n++] = q;
    }

    void getline()
    {
        for (int i = 0; i < n; i++)
        {
            l[i] = Line(p[i], p[(i + 1) % n]);
        }
    }

    struct cmp
    {
        Point p;
        cmp(const Point &p0) { p = p0; }
        bool operator()(const Point &aa, const Point &bb)
        {
            Point a = aa, b = bb;
            int d = sgn((a - p) ^ (b - p));
            if (d == 0)
            {
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d > 0;
        }
    };

    // 进行极角排序，排序完p[0]为最左下角的点
    void norm()
    {
        Point mi = p[0];
        for (int i = 1; i < n; i++)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }

    // 得到凸包，里面的点编号为0~n-1 [LightOJ 1203 | LightOJ 1239]
    // 注意如果有影响，要特判下所有点共点，或者共线的特殊情况
    void getconvex(Polygon &convex)
    {
        sort(p, p + n);
        convex.n = n;
        for (int i = 0; i < min(n, 2); i++)
        {
            convex.p[i] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--; // 特判
        if (n <= 2)
            return;
        int &top = convex.n;
        top = 1;
        for (int i = 2; i < n; i++)
        {
            while (top && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n - 2];
        for (int i = n - 3; i >= 0; i--)
        {
            while (top != temp && sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--; // 特判
        convex.norm(); // 原来得到的是顺时针的点，排序后逆时针
    }
};

Polygon a, b, ca, cb;

int check()
{
    for (int i = 0; i < ca.n; i++)
    {
        for (int j = 0; j < cb.n; j++)
        {
            if (ca.l[i].segcrossseg(cb.l[j]) != 0)
            {
                return 0;
            }
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
        a.n = b.n = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            if (z == 1)
            {
                a.add(Point(x, y));
            }
            else
            {
                b.add(Point(x, y));
            }
        }
        a.getconvex(ca);
        b.getconvex(cb);
        ca.getline();
        cb.getline();
        puts(check() ? "Successful!" : "Infinite loop!");
    }
    return 0;
}