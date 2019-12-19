#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxp = 307;

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

    Point() {}

    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    void input()
    {
        scanf("%lf %lf", &x, &y);
    }

    Point operator+(const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }

    Point operator/(const double &k) const
    {
        return Point(x / k, y / k);
    }

    double operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }

    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }

    Point operator*(const double &k) const
    {
        return Point(x * k, y * k);
    }

    double distance(Point &p)
    {
        return hypot(x - p.x, y - p.y);
    }

    double rad(Point &a, Point &b)
    {
        Point p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }

    double len()
    {
        return hypot(x, y);
    }

    Point trunc(double r)
    {
        double l = len();
        if (!sgn(l))
            return *this;
        r /= l;
        return Point(x * r, y * r);
    }

    double len2()
    {
        return x * x + y * y;
    }
};

struct Line
{
    Point s, e;

    Line() {}

    Line(Point _s, Point _e)
    {
        s = _s;
        e = _e;
    }

    double length()
    {
        return s.distance(e);
    }

    double dispointtoline(Point &p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }

    Point lineprog(Point &p)
    {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }
};

struct Circle
{
    Point p;
    double r;

    Circle() {}

    Circle(Point _p, double _r)
    {
        p = _p;
        r = _r;
    }

    int relation(Point &b)
    {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int relationline(Line &v)
    {
        double dst = v.dispointtoline(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int pointcrossline(Line &v, Point &p1, Point &p2)
    {
        if (!(*this).relationline(v))
            return 0;
        Point a = v.lineprog(p);
        double d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if (sgn(d) == 0)
        {
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }

    double areatriangle(Point &a, Point &b)
    {
        if (sgn((p - a) ^ (p - b)) == 0)
            return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a, b);
        Point p1, p2;
        if (pointcrossline(l, q[1], q[2]) == 2)
        {
            if (sgn((a - q[1]) * (b - q[1])) < 0)
                q[len++] = q[1];
            if (sgn((a - q[2]) * (b - q[2])) < 0)
                q[len++] = q[2];
        }
        q[len++] = b;
        if (len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0)
            swap(q[1], q[2]);
        double res = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (relation(q[i]) == 0 || relation(q[i + 1]) == 0)
            {
                double arg = p.rad(q[i], q[i + 1]);
                res += r * r * arg / 2.0;
            }
            else
            {
                res += fabs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
            }
        }
        return res;
    }
};

struct Polygon
{
    int n;
    Point p[maxp];
    Line l[maxp];

    void input(int _n)
    {
        n = _n;
        for (int i = 0; i < n; i++)
        {
            p[i].input();
        }
    }

    double getarea()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (p[i] ^ p[(i + 1) % n]);
        }
        return fabs(sum) / 2;
    }

    double areacircle(Circle &c)
    {
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n;
            if (sgn((p[j] - c.p) ^ (p[i] - c.p)) >= 0)
            {
                ans += c.areatriangle(p[i], p[j]);
            }
            else
            {
                ans -= c.areatriangle(p[i], p[j]);
            }
        }
        return fabs(ans);
    }
};

int main()
{
    int n, m;
    scanf("%d", &n);
    Polygon poly;
    poly.input(n);
    double polyarea = poly.getarea();
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        Point pos;
        double p, q;
        pos.input();
        scanf("%lf %lf", &p, &q);
        double l = 0, r = 1e5;
        while (l + eps < r)
        {
            double mid = (l + r) / 2.0;
            Circle c = Circle(pos, mid);
            if (poly.areacircle(c) >= polyarea * (1 - p / q))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        printf("%.8f\n", l);
    }
    return 0;
}