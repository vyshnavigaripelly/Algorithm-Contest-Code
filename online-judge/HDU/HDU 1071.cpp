#include <cstdio>
#include <cmath>
using namespace std;

double a, k, Pa, Pb, Pc, Lk, Lb;

double Solve(double x)
{
    return (Pa * pow(x, 3) / 3.0 + Pb * pow(x, 2) / 2.0 + Pc * x) - (Lk * pow(x, 2) / 2.0 + Lb * x);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double x1, y1, x2, y2, x3, y3;
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
        a = (y2 - y1) / pow(x2 - x1, 2);
        k = (y3 - y2) / (x3 - x2);
        Pa = a;
        Pb = -2.0 * a * x1;
        Pc = a * x1 * x1 + y1;
        Lk = k;
        Lb = -k * x2 + y2;
        printf("%lf %lf %lf %lf %lf\n", Pa, Pb, Pc, Lk, Lb);
        printf("%.2lf\n", Solve(x3) - Solve(x2));
    }
    return 0;
}
