#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxn = 100;

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
    double len() { return hypot(x, y); }

    double distance(Point p) { return hypot(x - p.x, y - p.y); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    Line(Point p, double angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
            e = (s + Point(0, 1));
        else
            e = (s + Point(1, tan(angle)));
    }

    bool operator==(Line v) { return (s == v.s) && (e == v.e); }

    void input()
    {
        s.input();
        e.input();
    }
    void adjust()
    {
        if (e < s)
            swap(s, e);
    }
    int relation(Point p)
    {
        int c = sgn((p - s) ^ (e - s));
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }
};

struct Circle
{
    Point p;
    double r;

    Circle() {}
    Circle(Point pp, double rr) { p = pp, r = rr; }
    Circle(double x, double y, double rr) { p = Point(x, y), r = rr; }

    bool operator==(Circle v) { return (p == v.p) && sgn(r - v.r) == 0; }
    bool operator<(Circle v) const { return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0)); }

    void input()
    {
        p.input();
        scanf("%lf", &r);
    }
    void output()
    {
        printf("%.2f %.2f %.2f\n", p.x, p.y, r);
    }

    int relation(Point b)
    {
        double dst = b.distance(p);
        if (sgn(dst - r) < 0)
            return 2;
        else if (sgn(dst - r) == 0)
            return 1;
        return 0;
    }

    int relationcircle(Circle v)
    {
        double d = p.distance(v.p);
        if (sgn(d - r - v.r) > 0)
            return 5;
        if (sgn(d - r - v.r) == 0)
            return 4;
        double l = fabs(r - v.r);
        if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0)
            return 3;
        if (sgn(d - l) == 0)
            return 2;
        if (sgn(d - l) < 0)
            return 1;
        return assert(0), 0;
    }
};

struct Circles
{
    Circle c[maxn];
    double ans[maxn];
    double pre[maxn];
    int n;

    Circles() {}

    void add(Circle cc)
    {
        c[n++] = cc;
    }

    bool inner(Circle x, Circle y)
    {
        if (x.relationcircle(y) != 1)
            return 0;
        return sgn(x.r - y.r) <= 0 ? 1 : 0;
    }

    void init_or()
    {
        bool mark[maxn] = {0};
        int i, j, k = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                if (i != j && !mark[j])
                {
                    if ((c[i] == c[j]) || inner(c[i], c[j]))
                        break;
                }
            if (j < n)
                mark[i] = 1;
        }
        for (i = 0; i < n; i++)
            if (!mark[i])
                c[k++] = c[i];
        n = k;
    }

    double areaarc(double th, double r)
    {
        return 0.5 * r * r * (th - sin(th));
    }

    void getarea()
    {
        memset(ans, 0, sizeof(ans));
        vector<pair<double, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.clear();
            v.push_back(make_pair(-pi, 1));
            v.push_back(make_pair(pi, -1));
            for (int j = 0; j < n; j++)
                if (i != j)
                {
                    Point q = (c[j].p - c[i].p);
                    double ab = q.len(), ac = c[i].r, bc = c[j].r;
                    if (sgn(ab + ac - bc) <= 0)
                    {
                        v.push_back(make_pair(-pi, 1));
                        v.push_back(make_pair(pi, -1));
                        continue;
                    }
                    if (sgn(ab + bc - ac) <= 0)
                        continue;
                    if (sgn(ab - ac - bc) > 0)
                        continue;
                    double th = atan2(q.y, q.x), fai = acos((ac * ac + ab * ab - bc * bc) / (2.0 * ac * ab));
                    double a0 = th - fai;
                    if (sgn(a0 + pi) < 0)
                        a0 += 2 * pi;
                    double a1 = th + fai;
                    if (sgn(a1 - pi) > 0)
                        a1 -= 2 * pi;
                    if (sgn(a0 - a1) > 0)
                    {
                        v.push_back(make_pair(a0, 1));
                        v.push_back(make_pair(pi, -1));
                        v.push_back(make_pair(-pi, 1));
                        v.push_back(make_pair(a1, -1));
                    }
                    else
                    {
                        v.push_back(make_pair(a0, 1));
                        v.push_back(make_pair(a1, -1));
                    }
                }
            sort(v.begin(), v.end());
            int cur = 0;
            for (int j = 0; j < v.size(); j++)
            {
                if (cur && sgn(v[j].first - pre[cur]))
                {
                    ans[cur] += areaarc(v[j].first - pre[cur], c[i].r);
                    ans[cur] += 0.5 * (Point(c[i].p.x + c[i].r * cos(pre[cur]), c[i].p.y + c[i].r * sin(pre[cur])) ^
                                       Point(c[i].p.x + c[i].r * cos(v[j].first), c[i].p.y + c[i].r * sin(v[j].first)));
                }
                cur += v[j].second;
                pre[cur] = v[j].first;
            }
        }
        for (int i = 1; i < n; i++)
            ans[i] -= ans[i + 1];
    }
};

Circles c;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double x, y, r;
        scanf("%lf %lf %lf", &x, &y, &r);
        c.add(Circle(Point(x, y), r));
    }
    c.init_or();
    c.getarea();
    printf("%.5f\n", accumulate(c.ans, c.ans + n + 1, 0.0));
    return 0;
}