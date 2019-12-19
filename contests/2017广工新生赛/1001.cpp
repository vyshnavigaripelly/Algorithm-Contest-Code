#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double pi = 3.141592653;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x = 1, y = 1;
        cin >> n >> m;
        double dist = 0;
        double r = 0.5 / sin(pi / n);
        while (m--)
        {
            x = y;
            cin >> y;
            dist += r * sin(pi * abs(y - x) / n) * 2;
        }
        printf("%.5lf\n", dist);
    }
    return 0;
}
