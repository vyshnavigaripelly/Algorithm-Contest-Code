#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 1e5 + 7;
const double eps = 1e-4;

struct Point
{
    double x, y;

    Point() { x = 0, y = 0; }
    Point(double xx, double yy) { x = xx, y = yy; }

    bool operator==(const Point &b) const { return x == b.x && y == b.y; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator/(double k) const { return Point(x / k, y / k); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    void input() { scanf("%lf %lf", &x, &y); }
    Point rotleft() { return Point(-y, x); }
    double distance(Point p) { return hypot(x - p.x, y - p.y); }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    Point crosspoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s),
               a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};

struct Circle
{
    Point p;
    double r;
    Circle() {}
    Circle(Point a, Point b, Point c)
    {
        Line u = Line((a + b) / 2, (a + b) / 2 + (b - a).rotleft());
        Line v = Line((b + c) / 2, (b + c) / 2 + (c - b).rotleft());
        p = u.crosspoint(v);
        r = p.distance(a);
    }
};

Point arr[N];

int main()
{
    srand(time(0) & 19260817 * ~time(0) | 114514 ^ 1919810);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            arr[i].input();
        }
        if (n == 1 || n == 2)
        {
            printf("%.6f %.6f %.6f\n", arr[0].x, arr[0].y, 0.0);
        }
        else if (n == 3 || n == 4)
        {
            Point p = (arr[0] + arr[1]) / 2;
            printf("%.6f %.6f %.6f\n", p.x, p.y, p.distance(arr[0]));
        }
        else
        {
            int flag = 0;
            while (!flag)
            {
                Point a = arr[rand() % n], b, c;
                do
                {
                    b = arr[rand() % n];
                } while (b == a);
                do
                {
                    c = arr[rand() % n];
                } while (c == b || c == a);
                Circle cir = Circle(a, b, c);
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (fabs(arr[i].distance(cir.p) - cir.r) < eps)
                    {
                        cnt++;
                    }
                }
                if (cnt >= (n + 1) / 2)
                {
                    printf("%.6f %.6f %.6f\n", cir.p.x, cir.p.y, cir.r);
                    flag = 1;
                }
            }
        }
    }
    return 0;
}