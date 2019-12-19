#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main()
{
    double n, R;
    scanf("%lf %lf", &n, &R);
    double ang = 2 * pi / n / 2;
    double d = sin(ang) * R * 2;
    double r = R * d / (2 * R - d);
    printf("%.7f", r);
    return 0;
}