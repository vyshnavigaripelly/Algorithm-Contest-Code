#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const double eps = 1e-8;
const double INF = 1e20;
const double pi = acos(-1.0);
const int maxp = 1e5 + 7;

bool read(int &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
        return 0;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

inline double sqr(double x) { return x * x; }

struct Point
{
    double x, y;

    Point() { x = 1; }
    Point(double xx, double yy) { x = xx, y = yy; }

    bool operator==(Point b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
    bool operator<(Point b) const { return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const double &k) const { return Point(x * k, y * k); }
    Point operator/(const double &k) const { return Point(x / k, y / k); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    void input() { scanf("%lf%lf", &x, &y); }
    void output() { printf("%.2f %.2f\n", x, y); }

    double distance(Point p) { return hypot(x - p.x, y - p.y); }

    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
};

struct Polygon
{
    int n;
    Point p[maxp];

    void input(int nn)
    {
        n = nn;
        for (int i = 0; i < n; i++)
            p[i].input();
    }
    void add(Point q) { p[n++] = q; }

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

    void norm()
    {
        Point mi = p[0];
        for (int i = 1; i < n; i++)
            mi = min(mi, p[i]);
        sort(p, p + n, cmp(mi));
    }

    void graham(Polygon &convex)
    {
        norm();
        int &top = convex.n;
        top = 0;
        if (n == 1)
        {
            top = 1;
            convex.p[0] = p[0];
            return;
        }
        if (n == 2)
        {
            top = 2;
            convex.p[0] = p[0];
            convex.p[1] = p[1];
            if (convex.p[0] == convex.p[1])
                top--;
            return;
        }
        convex.p[0] = p[0];
        convex.p[1] = p[1];
        top = 2;
        for (int i = 2; i < n; i++)
        {
            while (top > 1 && sgn((convex.p[top - 1] - convex.p[top - 2]) ^ (p[i] - convex.p[top - 2])) <= 0)
                top--;
            convex.p[top++] = p[i];
        }
        if (convex.n == 2 && (convex.p[0] == convex.p[1]))
            convex.n--;
    }
};

Polygon poly, conv;

int main()
{
    int t;
    read(t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(&poly, 0, sizeof(poly));
        memset(&conv, 0, sizeof(conv));
        int n;
        read(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            read(x);
            read(y);
            poly.add({x, y});
        }
        poly.graham(conv);
        double ans = INF;
        for (int i = 0; i < conv.n; i++)
        {
            ans = min(ans, conv.p[i].rad(conv.p[(i - 1 + conv.n) % conv.n], conv.p[(i + 1) % conv.n]));
        }
        printf("Case %d: %.8f\n", cas, ans / pi * 180);
    }
    return 0;
}