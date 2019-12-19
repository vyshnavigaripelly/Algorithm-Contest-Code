#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const double EPS = 1e-8;

int bcj[1007];

struct Point
{
    double x, y;
} arr[1007];

int find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = find(bcj[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    bcj[y] = x;
}

double dist(int i, int j)
{
    return hypot(arr[i].x - arr[j].x, arr[i].y - arr[j].y);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(bcj, -1, sizeof(bcj));
        int n;
        double r;
        scanf("%d %lf", &n, &r);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf %lf", &arr[i].x, &arr[i].y);
        }
        if (r > 50)
        {
            puts("No");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (arr[i].x - 2 * r <= EPS)
            {
                merge(0, i);
            }
            if (100 - arr[i].x - 2 * r <= EPS)
            {
                merge(i, n + 1);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (dist(i, j) - 2 * r <= EPS)
                {
                    merge(i, j);
                }
            }
        }
        puts(find(0) != find(n + 1) ? "Yes" : "No");
    }
    return 0;
}