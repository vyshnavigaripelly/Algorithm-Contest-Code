#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

double w, h;

struct Point
{
    double x, y;

    Point() { x = 0, y = 0; }
    Point(double xx, double yy) { x = xx, y = yy; }
};

int calc(double da, double db, double dc, int x, int y, int z)
{
    Point p[3];
    p[x] = Point(0, 0);
    if (da > w)
    {
        p[y] = Point(w, sqrt(da * da - w * w));
    }
    else
    {
        p[y] = Point(da, 0);
    }
    double ang = atan(p[y].y / p[y].x) + acos((da * da + db * db - dc * dc) / (2 * da * db));
    p[z] = Point(db * cos(ang), db * sin(ang));
    if (p[z].x >= -eps && p[z].x <= w + eps && p[z].y >= -eps && p[z].y <= h + eps)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%.8f %.8f ", p[i].x, p[i].y);
        }
        puts("");
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double a, b, c;
        scanf("%lf %lf %lf %lf %lf", &w, &h, &a, &b, &c);
        if (calc(a, b, c, 0, 1, 2))
            continue;
        if (calc(a, c, b, 1, 0, 2))
            continue;
        if (calc(b, a, c, 0, 2, 1))
            continue;
        if (calc(b, c, a, 2, 0, 1))
            continue;
        if (calc(c, a, b, 1, 2, 0))
            continue;
        if (calc(c, b, a, 2, 1, 0))
            continue;
        assert(0);
    }
    return 0;
}