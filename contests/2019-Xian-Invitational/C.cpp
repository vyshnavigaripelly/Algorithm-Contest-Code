#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

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

    double len() { return hypot(x, y); }
    double distance(Point p) { return hypot(x - p.x, y - p.y); }

    double rad(Point a, Point b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }

    Point trunc(double r)
    {
        double l = len();
        if (!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }

    Point rotleft() { return Point(-y, x); }
    Point rotright() { return Point(y, -x); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }
};

struct Circle
{
    Point p;
    double r;

    Circle() {}
    Circle(double x, double y, double rr) { p = Point(x, y), r = rr; }

    int relation(Point b)
    {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int tangentline(Point q, Line &u, Line &v)
    {
        int x = relation(q);
        if (x == 2)
            return 0;
        if (x == 1)
        {
            u = Line(q, q + (q - p).rotleft());
            v = u;
            return 1;
        }
        double d = p.distance(q);
        double l = r * r / d;
        double h = sqrt(r * r - l * l);
        u = Line(q, p + ((q - p).trunc(l) + (q - p).rotleft().trunc(h)));
        v = Line(q, p + ((q - p).trunc(l) + (q - p).rotright().trunc(h)));
        return 2;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double rx, ry, r, x, y;
        scanf("%lf %lf %lf %lf %lf", &rx, &ry, &r, &x, &y);
        Point a = Point(rx, ry - r), b = Point(x, y);
        Circle c = Circle(rx, ry, r);
        Line u, v;
        Point st, tmp;
        Point left = Point(rx - r, ry), right = Point(rx + r, ry);
        c.tangentline(b, u, v);
        if (u.e.y < v.e.y)
            tmp = u.e;
        else
            tmp = v.e;
        if (tmp.y < ry)
        {
            if (b.x > rx)
                st = right;
            else
                st = left;
        }
        else
            st = tmp;
        double ang = c.p.rad(st, a);
        double ans = ang * c.r + st.distance(b);
        printf("%.4f\n", ans);
    }
    return 0;
}