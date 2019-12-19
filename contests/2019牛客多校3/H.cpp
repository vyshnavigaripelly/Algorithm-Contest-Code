#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node
{
    double ang;
    int idx;
} ang[1007];

long long x[1007], y[1007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &x[i], &y[i]);
        }
        long long xx = -20000000, yy = -1005;
        for (int i = 0; i < n; i++)
        {
            ang[i].ang = atan2(y[i] - yy, x[i] - xx);
            ang[i].idx = i;
        }
        sort(ang, ang + n, [](const Node &a, const Node &b) {
            return a.ang < b.ang;
        });
        int mid = ang[n / 2].idx;
        long long ansx = x[mid], ansy = y[mid];
        ansx = (ansx - xx) * 40 + xx + 1;
        ansy = (ansy - yy) * 40 + yy;
        printf("%lld %lld %lld %lld\n", xx, yy, ansx, ansy);
    }
    return 0;
}