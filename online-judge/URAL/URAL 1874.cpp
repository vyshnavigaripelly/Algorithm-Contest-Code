#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

double a, b;

double calc(double ansm)
{
    double p = (a + b + ansm) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - ansm)) + ansm * ansm / 4;
}

int main()
{
    scanf("%lf %lf", &a, &b);
    if (a > b)
    {
        swap(a, b);
    }
    double ansl = b - a, ansr = b + a;
    while (ansl + eps < ansr)
    {
        double ansm = (ansl + ansr) / 2;
        double ansm2 = (ansm + ansr) / 2;
        if (calc(ansm) < calc(ansm2))
        {
            ansl = ansm;
        }
        else
        {
            ansr = ansm2;
        }
    }
    printf("%.8f\n", calc(ansl));
    return 0;
}