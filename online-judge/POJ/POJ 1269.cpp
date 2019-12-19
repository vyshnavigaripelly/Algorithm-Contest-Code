#include <iostream>
#include <cstdio>

using namespace std;

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) { x = xx, y = yy; }

    void input() { scanf("%lf %lf", &x, &y); }

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    void input() { s.input(), e.input(); }

    // 点和直线关系 {1:在左侧, 2:在右侧, 3:在直线上}
    int relation(Point p)
    {
        int c = (p - s) ^ (e - s);
        if (c < 0)
            return 1;
        else if (c > 0)
            return 2;
        else
            return 3;
    }

    // 两直线关系 {0:平行, 1:重合, 2:相交}
    int linecrossline(Line v)
    {
        if (((e - s) ^ (v.e - v.s)) == 0)
            return v.relation(s) == 3;
        return 2;
    }

    // 求两直线的交点，要保证两直线不平行或重合
    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    puts("INTERSECTING LINES OUTPUT");
    while (n--)
    {
        Line a, b;
        a.input();
        b.input();
        int d = a.linecrossline(b);
        if (d == 0)
        {
            puts("NONE");
        }
        else if (d == 1)
        {
            puts("LINE");
        }
        else
        {
            Point p = a.crosspoint(b);
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}