#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = acos(-1.0);

int main()
{
    int n, d;
    while (~scanf("%d %d", &n, &d))
    {
        double ans = 0;
        while (n--)
        {
            int k;
            scanf("%d", &k);
            ans += 0.5 * d * d * sin(k / 360.0 * 2 * pi);
        }
        printf("%.3f\n", ans);
    }
    return 0;
}