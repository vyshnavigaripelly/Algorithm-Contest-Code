#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

struct Point
{
    double x, y;
} p[2007];

double ang[4007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        long long cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            int tot = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                ang[tot] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
                if (ang[tot] < 0)
                {
                    ang[tot] += 2 * pi;
                }
                tot++;
            }
            sort(ang, ang + tot);
            for (int j = 0; j < tot; j++)
            {
                ang[j + tot] = ang[j] + 2 * pi;
            }
            int pos1 = 0, pos2 = 0, pos3 = 0;
            for (int j = 0; j < tot; j++)
            {
                while (pos1 < 2 * tot && ang[pos1] == ang[j])
                {
                    pos1++;
                }
                while (pos2 < 2 * tot && ang[pos2] - ang[j] < pi / 2)
                {
                    pos2++;
                }
                while (pos3 < 2 * tot && ang[pos3] - ang[j] < pi)
                {
                    pos3++;
                }
                cnt1 += pos2 - pos1;
                cnt2 += 2 * (pos3 - pos2);
            }
        }
        printf("%lld\n", (cnt1 - cnt2) / 3);
    }
    return 0;
}