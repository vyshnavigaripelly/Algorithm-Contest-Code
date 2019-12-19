#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double H, h, D;
        scanf("%lf %lf %lf", &H, &h, &D);
        double ans = sqrt((H - h) * D);
        double sum = (H - h) * D / H;
        if (ans >= D)
        {
            printf("%.3lf\n", h);
        }
        else if (ans < sum)
        {
            printf("%.3lf\n", h * D / H);
        }
        else
        {
            double q = H + D - ans - (H - h) * D / ans;
            printf("%.3lf\n", q);
        }
    }
    return 0;
}
