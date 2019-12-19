#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const int maxp = 1e5 + 7;

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
    long long x, y;

    Point() {}
    Point(long long xx, long long yy) { x = xx, y = yy; }

    bool operator==(Point b) const { return x == b.x && y == b.y; }
    bool operator<(Point b) const { return x == b.x ? y < b.y : x < b.x; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    long long operator^(const Point &b) const { return x * b.y - y * b.x; }
    long long operator*(const Point &b) const { return x * b.x + y * b.y; }

    void input() { scanf("%lld %lld", &x, &y); }

    double distance(Point p) { return hypot(x - p.x, y - p.y); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    Point getdir() { return e - s; }
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

    long long area2()
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (p[i] ^ p[(i + 1) % n]);
        }
        return abs(sum);
    }

    void minkowski(Polygon &b, Polygon &c)
    {
        getline();
        b.getline();
        c.p[0] = p[0] + b.p[0];
        int &tot = c.n = 1;
        int p1 = 0, p2 = 0;
        while (p1 < n && p2 < b.n)
        {
            c.p[tot] = c.p[tot - 1] + ((l[p1].getdir() ^ b.l[p2].getdir()) >= 0 ? l[p1++].getdir() : b.l[p2++].getdir());
            tot++;
        }
        while (p1 < n)
        {
            c.p[tot] = c.p[tot - 1] + l[p1++].getdir();
            tot++;
        }
        while (p2 < b.n)
        {
            c.p[tot] = c.p[tot - 1] + b.l[p2++].getdir();
            tot++;
        }
    }
};

Polygon a, b, c, aa, bb, cc;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    a.input(n);
    b.input(m);
    a.graham(aa);
    b.graham(bb);
    aa.minkowski(bb, c);
    c.graham(cc);
    printf("%lld\n", cc.area2());
    return 0;
}