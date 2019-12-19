#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-6;

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
} p[50007];

double dist(const Point &a, const Point &b)
{
    Point tmp = a - b;
    return sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
}

int check(int left, int right, int a, int b)
{
    return !(fabs(dist(p[left], p[a]) - dist(p[right], p[a])) > eps ||
             fabs(dist(p[left], p[b]) - dist(p[right], p[b])) > eps);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < 2 * n; i += 2)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        p[2 * n] = p[0];
        for (int i = 1; i < 2 * n; i += 2)
        {
            p[i].x = (p[i - 1].x + p[i + 1].x) / 2;
            p[i].y = (p[i - 1].y + p[i + 1].y) / 2;
        }
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i, right = i;
            while (true)
            {
                left++;
                right--;
                if (right == -1)
                {
                    right = 2 * n - 1;
                }
                if (left == i + n)
                {
                    flag = 1;
                    break;
                }
                if (!check(left, right, i, i + n))
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}