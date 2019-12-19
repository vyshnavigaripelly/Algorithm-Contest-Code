#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double d;
        scanf("%lf", &d);
        if (d >= 1 && d <= 3)
        {
            printf("N\n");
        }
        else if (d == 0)
        {
            printf("Y %.9f %.9f\n", 0.0, 0.0);
        }
        else
        {
            double a = 0.5 * (-sqrt(d - 4) * sqrt(d) + d);
            double b = 0.5 * (sqrt(d - 4) * sqrt(d) + d);
            printf("Y %.9f %.9f\n", a, b);
        }
    }
    return 0;
}