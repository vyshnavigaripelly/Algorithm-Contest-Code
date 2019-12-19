#include <iostream>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    double X1, Y1, X2, Y2;
    X1 = (b * y1 + c) / (-a);
    Y1 = (a * x1 + c) / (-b);
    X2 = (b * y2 + c) / (-a);
    Y2 = (a * x2 + c) / (-b);
    double ans = 1e18;
    ans = min(ans, dist(X1, y1, X2, y2) + fabs(x1 - X1) + fabs(x2 - X2));
    ans = min(ans, dist(X1, y1, x2, Y2) + fabs(x1 - X1) + fabs(y2 - Y2));
    ans = min(ans, dist(x1, Y1, X2, y2) + fabs(y1 - Y1) + fabs(x2 - X2));
    ans = min(ans, dist(x1, Y1, x2, Y2) + fabs(y1 - Y1) + fabs(y2 - Y2));
    ans = min(ans, fabs(x1 - x2) + fabs(y1 - y2));
    printf("%.10f", ans);
    return 0;
}