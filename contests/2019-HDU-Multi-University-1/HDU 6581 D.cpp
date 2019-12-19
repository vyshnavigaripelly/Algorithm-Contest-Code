#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 7;

double l[N], s[N], v[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n + 1; i++)
        {
            scanf("%lf", &l[i]);
        }
        for (int i = 1; i <= n + 1; i++)
        {
            scanf("%lf", &s[i]);
        }
        for (int i = 1; i <= n + 1; i++)
        {
            scanf("%lf", &v[i]);
        }
        double ans = 0, len = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            if (i != 1)
            {
                len += l[i];
            }
            double time = (s[i] + len) / v[i];
            ans = max(ans, time);
        }
        printf("%.8f\n", ans);
    }
    return 0;
}