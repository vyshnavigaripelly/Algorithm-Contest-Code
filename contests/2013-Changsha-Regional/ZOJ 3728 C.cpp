#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    return 1;
}

struct Point
{
    double x, y;

    Point() { x = 0, y = 0; }
    Point(double xx, double yy) { x = xx, y = yy; }

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const double &k) const { return Point(x * k, y * k); }
    Point operator/(const double &k) const { return Point(x / k, y / k); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    void output() { printf("%.4f %.4f\n", x, y); }
    double len() { return hypot(x, y); }
    double len2() { return x * x + y * y; }
    double distance(Point p) { return hypot(x - p.x, y - p.y); }

    Point trunc(double r)
    {
        double l = len();
        if (!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    double length() { return s.distance(e); }

    double dispointtoline(Point p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }

    double dispointtoseg(Point p)
    {
        if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    }

    Point lineprog(Point p)
    {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }
};

struct Circle
{
    Point p;
    double r;

    Circle() {}
    Circle(Point pp, double rr) { p = pp, r = rr; }

    int relationseg(Line v)
    {
        double dst = v.dispointtoseg(p);
        if (sgn(dst - r) < 0)
            return 2;
        if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int relationline(Line v)
    {
        double dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0)
            return 2;
        if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int pointcrossline(Line v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v))
            return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
};

int main()
{
    double Rm, R, r, x, y, vx, vy;
    while (~scanf("%lf %lf %lf %lf %lf %lf %lf", &Rm, &R, &r, &x, &y, &vx, &vy))
    {
        Circle metal = Circle(Point(0.0, 0.0), Rm + r), range = Circle(Point(0.0, 0.0), R + r);
        Line dir = Line(Point(x, y), Point(x + vx, y + vy)),
             dir2 = Line(Point(x, y), Point(x + 30000 * vx, y + 30000 * vy));
        Point pm1, pm2, pR1, pR2;
        int metalnum = metal.pointcrossline(dir, pm1, pm2),
            rangenum = range.pointcrossline(dir, pR1, pR2);
        double ans = 0;
        if (rangenum < 2 || range.relationseg(dir2) < 2)
        {
            ans = 0;
        }
        else
        {
            if (metalnum == 0)
                ans = (pR1 - pR2).len() / dir.length();
            else
                ans = fabs((pR1 - pR2).len() - (pm1 - pm2).len()) / dir.length();
        }
        printf("%.4f\n", ans);
    }
    return 0;
}