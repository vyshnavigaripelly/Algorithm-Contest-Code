#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long arr[50];

int main()
{
    for (long long i = 1; i <= 15; i++)
    {
        arr[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            arr[i] *= i;
        }
    }
    long long n;
    while (~scanf("%lld", &n))
    {
        long long ans = 1;
        for (ans = 1; ans <= 15; ans++)
        {
            if (arr[ans] > n)
            {
                break;
            }
        }
        printf("%lld\n", ans - 1);
    }
    return 0;
}