#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double r, h, x, y, z, vx, vy, vz;

struct Point
{
    double x, y, z;

    Point() {}
    Point(double xx, double yy, double zz) { x = xx, y = yy, z = zz; }

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y, z + b.z); }
    Point operator*(double b) { return Point(b * x, b * y, b * z); }

    void output()
    {
        printf("(%.8f, %.8f, %.8f)\n", x, y, z);
    }
};

int check(double t)
{
    Point p = Point(vx, vy, vz) * t + Point(x, y, z);
    return p.x * p.x + p.y * p.y <= r * r && p.z >= 0 && p.z <= h;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        // sqrt(x^2 + y^2) / r == (h - z) / h
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &r, &h, &x, &y, &z, &vx, &vy, &vz);
        double a = h * h * (vx * vx + vy * vy) - r * r * vz * vz;
        double b = 2 * (h * h * (vx * x + vy * y) + h * r * r * vz - r * r * vz * z);
        double c = h * h * (x * x + y * y - r * r) + r * r * (2 * h * z - z * z);
        double t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        double ans = 1e18;
        if (check(t1))
        {
            ans = min(ans, t1);
        }
        if (check(t2))
        {
            ans = min(ans, t2);
        }
        printf("Case %d: %.8f\n", cas, ans);
    }
    return 0;
}