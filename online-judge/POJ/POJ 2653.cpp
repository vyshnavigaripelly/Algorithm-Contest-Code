#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double eps = 1e-8;

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) { x = xx, y = yy; }

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    void input()
    {
        scanf("%lf %lf", &x, &y);
    }
};

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    void input()
    {
        s.input();
        e.input();
    }

    // 两线段相交判断 {2:规范相交, 1:非规范相交, 0:不相交}
    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        int d3 = sgn((v.e - v.s) ^ (s - v.s));
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
} arr[100007];

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
        {
            arr[i].input();
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            for (int j = i + 1; j <= n && flag; j++)
            {
                if (arr[i].segcrossseg(arr[j]) != 0)
                {
                    flag = 0;
                }
            }
            if (flag)
            {
                ans.push_back(i);
            }
        }
        printf("Top sticks: ");
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d%s", ans[i], i < ans.size() - 1 ? ", " : ".\n");
        }
    }
    return 0;
}