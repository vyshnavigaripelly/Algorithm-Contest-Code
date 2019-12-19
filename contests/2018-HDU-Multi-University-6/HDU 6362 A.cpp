#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double pi = acos(-1.0);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double a, b;
        scanf("%lf %lf", &a, &b);
        printf("%.6f\n", 2.0 * b + pi * a - 5e-7);
    }
    return 0;
}