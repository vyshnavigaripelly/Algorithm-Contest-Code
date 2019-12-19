#include <iostream>

using namespace std;

double a, b, c;

double f(double x, double y)
{
    return a * x * x + b * x * y + c * y * y;
}

int main()
{
    while (~scanf("%lf %lf %lf", &a, &b, &c))
    {
        int flag = 1;
        for (int i = -500; i <= 500 && flag; i += 5)
        {
            for (int j = -500; j <= 500 && flag; j += 5)
            {
                if (f(i, j) < 0)
                {
                    flag = 0;
                }
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}