#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1507;

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

    void input() { scanf("%lf%lf", &x, &y); }
    void output() { printf("%.2f %.2f\n", x, y); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    bool operator==(Line v) { return (s == v.s) && (e == v.e); }

    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }

    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};

struct Polygon
{
    int n;
    Point p[maxp];
    Line l[maxp];

    void input(int nn)
    {
        n = nn;
        for (int i = 0; i < n; i++)
            p[i].input();
    }
    void add(Point q) { p[n++] = q; }
    void getline()
    {
        for (int i = 0; i < n; i++)
        {
            l[i] = Line(p[i], p[(i + 1) % n]);
        }
    }

    bool getdir()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
            sum += (p[i] ^ p[(i + 1) % n]);
        if (sgn(sum) > 0)
            return 1;
        return 0;
    }

    double area()
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (p[i] ^ p[(i + 1) % n]);
        }
        return fabs(sum) / 2;
    }
};

struct Halfplane : public Line
{
    double angle;

    Halfplane() {}
    Halfplane(Point ss, Point ee) { s = ss, e = ee; }
    Halfplane(Line v) { s = v.s, e = v.e; }

    bool operator<(const Halfplane &b) const { return angle < b.angle; }

    void calcangle() { angle = atan2(e.y - s.y, e.x - s.x); }
};

struct Halfplanes
{
    int n;
    Halfplane hp[maxp];
    Point p[maxp];
    int que[maxp];
    int st, ed;

    void push(Halfplane tmp)
    {
        hp[n++] = tmp;
    }

    void unique()
    {
        int m = 1;
        for (int i = 1; i < n; i++)
        {
            if (sgn(hp[i].angle - hp[i - 1].angle) != 0)
                hp[m++] = hp[i];
            else if (sgn((hp[m - 1].e - hp[m - 1].s) ^ (hp[i].s - hp[m - 1].s)) > 0)
                hp[m - 1] = hp[i];
        }
        n = m;
    }

    bool halfplaneinsert()
    {
        for (int i = 0; i < n; i++)
            hp[i].calcangle();
        sort(hp, hp + n);
        unique();
        que[st = 0] = 0;
        que[ed = 1] = 1;
        p[1] = hp[0].crosspoint(hp[1]);
        for (int i = 2; i < n; i++)
        {
            while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[ed] - hp[i].s)) < 0)
                ed--;
            while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[st + 1] - hp[i].s)) < 0)
                st++;
            que[++ed] = i;
            if (hp[i].parallel(hp[que[ed - 1]]))
                return false;
            p[ed] = hp[i].crosspoint(hp[que[ed - 1]]);
        }
        while (st < ed && sgn((hp[que[st]].e - hp[que[st]].s) ^ (p[ed] - hp[que[st]].s)) < 0)
            ed--;
        while (st < ed && sgn((hp[que[ed]].e - hp[que[ed]].s) ^ (p[st + 1] - hp[que[ed]].s)) < 0)
            st++;
        if (st + 1 >= ed)
            return false;
        return true;
    }

    void getconvex(Polygon &con)
    {
        p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
        con.n = ed - st + 1;
        for (int j = st, i = 0; j <= ed; i++, j++)
            con.p[i] = p[j];
    }
};

Polygon poly;
Halfplanes ha;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(&poly, 0, sizeof(poly));
        memset(&ha, 0, sizeof(ha));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            poly.add(Point(x, y));
        }
        if (poly.getdir() == 0)
        {
            for (int i = 0; i < n / 2; i++)
                swap(poly.p[i], poly.p[n - 1 - i]);
        }
        poly.getline();
        for (int i = 0; i < n; i++)
        {
            ha.push(poly.l[i]);
        }
        if (ha.halfplaneinsert())
        {
            Polygon conv;
            ha.getconvex(conv);
            printf("%.2f\n", conv.area());
        }
        else
        {
            puts("0.00");
        }
    }
    return 0;
}