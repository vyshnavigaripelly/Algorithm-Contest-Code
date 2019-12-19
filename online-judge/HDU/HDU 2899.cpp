#include <cstdio>
#include <cmath>
using namespace std;

double F(double x, double y)
{
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x, 2) - y * x;
}

double dF(double x, double y)
{
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2) + 10 * x - y;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double y;
        scanf("%lf", &y);
        double l = 0, r = 100, mid, eps = 1e-6;
        while (l + eps <= r)
        {
            mid = l + (r - l) / 2;
            if (dF(mid, y) <= 0)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        printf("%.4lf\n", F(mid, y));
    }
    return 0;
}
