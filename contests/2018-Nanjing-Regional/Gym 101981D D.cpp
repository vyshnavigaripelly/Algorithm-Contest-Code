#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Point
{
    double x, y, z;
} p[107];

double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
    }
    double step = 1e5, ans = 1e10, distmp = 0;
    int maxi = 0;
    Point tmp = {0, 0, 0};
    while (step > 1e-6)
    {
        for (int i = 0; i < n; i++)
        {
            if (dist(tmp, p[maxi]) < dist(tmp, p[i]))
            {
                maxi = i;
            }
        }
        distmp = dist(tmp, p[maxi]);
        ans = min(ans, distmp);
        tmp.x += (p[maxi].x - tmp.x) / distmp * step;
        tmp.y += (p[maxi].y - tmp.y) / distmp * step;
        tmp.z += (p[maxi].z - tmp.z) / distmp * step;
        // printf("%f %f %f\n", tmp.x, tmp.y, tmp.z);
        step *= 0.95;
    }
    printf("%.6f\n", ans);
    return 0;
}