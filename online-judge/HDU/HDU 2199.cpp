#include <cstdio>
#include <cmath>
using namespace std;

double F(double x)
{
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double y;
        scanf("%lf", &y);
        double l = 0, r = 100, mid, eps = 1e-8;
        if (y >= F(0) && y <= F(100))
        {

            while (l + eps <= r)
            {
                mid = l + (r - l) / 2;
                if (F(mid) <= y)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            printf("%.4lf\n", l);
        }
        else
        {
            printf("No solution!\n");
        }
    }
    return 0;
}
