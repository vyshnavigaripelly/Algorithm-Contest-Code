#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int x[100007], y[100007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        sort(x, x + n);
        sort(y, y + n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(y[i] - y[n / 2]);
        }
        for (int i = 0; i < n; i++)
        {
            x[i] -= i;
        }
        sort(x, x + n);
        for (int i = 0; i < n; i++)
        {
            ans += abs(x[i] - x[n / 2]);
        }
        printf("%d\n", ans);
    }
    return 0;
}