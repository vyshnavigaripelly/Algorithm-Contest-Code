#include <iostream>
#include <cmath>
#include <map>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-6;

double dist(double x1, double y1, double x2, double y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

pair<double, double> calper(double x1, double y1, double r1, double x2, double y2, double r2)
{
    double dd = dist(x1, y1, x2, y2);
    double d = sqrt(dd);
    if (dd > (r1 + r2) * (r1 + r2))
    {
        return make_pair(0, 0);
    }
    if (dd == (r1 - r2) * (r1 - r2))
    {
        return make_pair(0, 2 * PI * r2);
    }
    if (dd < (r1 - r2) * (r1 - r2))
    {
        return make_pair(0, 0);
    }
    double x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
    double t1 = 2 * acos(x / r1);
    double t2 = 2 * acos((d - x) / r2);
    return make_pair(t1 * r1, t2 * r2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m;
        double R;
        scanf("%d %lf", &m, &R);
        double ans = 0;
        ans += 2 * PI * R;
        while (m--)
        {
            double x, y, r;
            scanf("%lf %lf %lf", &x, &y, &r);
            auto tmp = calper(0, 0, R, x, y, r);
            ans = ans - tmp.first + tmp.second;
        }
        printf("%.8f\n", ans);
    }
    return 0;
}