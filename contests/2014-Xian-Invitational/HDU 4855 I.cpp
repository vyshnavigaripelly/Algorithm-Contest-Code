#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

struct Vector
{
    double x, y;
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Circle
{
    double x, y, r;
};

double ang[1007];
int n;

Circle c[207];

Vector operator+(Vector a, Vector b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(Vector a, Vector b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator*(Vector a, double b)
{
    return Vector(a.x * b, a.y * b);
}

Vector operator/(Vector a, double b)
{
    return Vector(a.x / b, a.y / b);
}

double Cross(Vector a, Vector b)
{
    return a.x * b.y - a.y * b.x;
}

Vector Rotate(Vector a, double rad)
{
    return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

double Length(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

double calc(double rad)
{
    double ret = 0;
    for (int i = 1; i <= n; i++)
    {
        Vector p = Rotate({c[i].x, c[i].y}, -rad);
        if (p.x > 0 && fabs(p.y) < c[i].r)
        {
            ret += 2 * sqrt(c[i].r * c[i].r - p.y * p.y);
        }
    }
    return ret;
}

int main()
{
    while (~scanf("%d", &n))
    {
        int angcnt = 0;
        ang[angcnt++] = PI;
        ang[angcnt++] = -PI;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf %lf %lf", &c[i].x, &c[i].y, &c[i].r);
            double angcenter = atan2(c[i].y, c[i].x),
                   angd = asin(c[i].r / Length({c[i].x, c[i].y})),
                   angl = angcenter - angd, angr = angcenter + angd;
            ang[angcnt++] = angcenter;
            ang[angcnt++] = angd;
            ang[angcnt++] = angl;
            ang[angcnt++] = angr;
            if (angl < -PI)
            {
                angl += 2 * PI;
            }
            if (angr > PI)
            {
                angr -= 2 * PI;
            }
        }
        sort(ang, ang + angcnt);
        angcnt = unique(ang, ang + angcnt) - ang;
        double ans = 0;
        for (int i = 0; i < angcnt - 1; i++)
        {
            double l = ang[i], r = ang[i + 1];
            while (r - l > eps)
            {
                double mid1 = (l + r) / 2,
                       mid2 = (mid1 + r) / 2,
                       ans1 = calc(mid1),
                       ans2 = calc(mid2);
                if (ans1 > ans2)
                {
                    r = mid2 - eps;
                    ans = max(ans, ans1);
                }
                else
                {
                    l = mid1 + eps;
                    ans = max(ans, ans2);
                }
            }
        }
        printf("%.8f\n", ans);
    }
    return 0;
}