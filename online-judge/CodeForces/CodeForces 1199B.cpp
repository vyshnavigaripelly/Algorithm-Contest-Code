#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double h, l;
    scanf("%lf %lf", &h, &l);
    printf("%.8f\n", (h * h + l * l) / (2 * h) - h);
    return 0;
}