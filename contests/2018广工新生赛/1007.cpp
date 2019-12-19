#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
        {
            puts("Impossble");
        }
        else
        {
            printf("%.8f\n", 1.0 * n * n / (2 * pi));
        }
    }
    return 0;
}