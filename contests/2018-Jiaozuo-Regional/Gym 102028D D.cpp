#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1.0);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double a, b, r, ang, ans;
        scanf("%lf %lf %lf %lf", &a, &b, &r, &ang);
        ang = ang * PI / 180.0;
        if (ang >= atan(b / (a + r)))
        {
            ans = sqrt((a + r) * (a + r) + b * b) - r;
        }
        else
        {
            ans = (a + r) * cos(ang) + b * sin(ang) - r;
        }
        printf("%.8f\n", ans);
    }
    return 0;
}