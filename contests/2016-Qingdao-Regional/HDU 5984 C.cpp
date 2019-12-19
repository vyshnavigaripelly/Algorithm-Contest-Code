#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double l, d;
        scanf("%lf %lf", &l, &d);
        printf("%.6f\n", (l <= d) ? 0 : log(l / d) + 1);
    }
    return 0;
}