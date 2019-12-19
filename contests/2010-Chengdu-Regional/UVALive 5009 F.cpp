#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const double eps = 1e-15;
const double INF = 1e15;

int arr[100007], brr[100007], crr[100007];
int n;

double calc(double x)
{
    double ans = -INF;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * x * x + brr[i] * x + crr[i]);
    }
    return ans;
}

double search()
{
    double l = 0, r = 1000;
    while (l + eps < r)
    {
        double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (calc(mid1) > calc(mid2))
        {
            l = mid1;
        }
        else
        {
            r = mid2;
        }
    }
    return l;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &arr[i], &brr[i], &crr[i]);
        }
        printf("%.4f\n", calc(search()));
    }
    return 0;
}