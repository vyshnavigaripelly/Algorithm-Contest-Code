#include <bits/stdc++.h>

using namespace std;

const int N = 1007;
const double eps = 1e-8;
const double inf = 1e20;

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
    Point(double xx, double yy) { x = xx, y = yy; }

    bool operator==(Point b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
    bool operator<(Point b) const { return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const double &k) const { return Point(x * k, y * k); }
    Point operator/(const double &k) const { return Point(x / k, y / k); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    void output() { printf("%.2f %.2f\n", x, y); }
    double len() { return hypot(x, y); }
    double len2() { return x * x + y * y; };
};

struct Line
{
    Point s, e;
    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    int linecrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2)
            return 2;
        return (d1 == 0 || d2 == 0);
    }

    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }

    Point lineprog(Point p)
    {
        return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
    }

    Point symmetrypoint(Point p)
    {
        Point q = lineprog(p);
        return Point(2 * q.x - p.x, 2 * q.y - p.y);
    }
};

struct Node
{
    Point p;
    double k;
};

Node arr[N];
Line li[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf %lf", &arr[i].p.x, &arr[i].p.y, &arr[i].k);
        }
        Point dir;
        scanf("%lf %lf", &dir.x, &dir.y);
        Line laser = Line(Point(0, 0), dir);
        for (int i = 0; i < n; i++)
        {
            li[i] = Line(arr[i].p, arr[(i + 1) % n].p);
        }
        double rest = 1;
        int ans = 0, now = -1;
        for (int i = 0; i < n; i++)
        {
            int flag = laser.linecrossseg(li[i]);
            if (flag == 2)
            {
                ans++;
                Point cross = laser.crosspoint(li[i]);
                Point reflect = li[i].symmetrypoint(laser.s);
                laser = Line(cross, cross + (cross - reflect));
                now = i;
                rest *= arr[now].k;
                break;
            }
            else if (flag == 1)
            {
                ans++;
                rest = 0;
                break;
            }
        }
        while (rest >= 1e-4)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == now)
                    continue;
                int flag = laser.linecrossseg(li[i]);
                if (flag == 2)
                {
                    ans++;
                    Point cross = laser.crosspoint(li[i]);
                    Point reflect = li[i].symmetrypoint(laser.s);
                    laser = Line(cross, cross + (cross - reflect));
                    now = i;
                    break;
                }
                else if (flag == 1)
                {
                    ans++;
                    rest = 0;
                    break;
                }
            }
            rest *= arr[now].k;
        }
        printf("%d\n", ans);
    }
    return 0;
}