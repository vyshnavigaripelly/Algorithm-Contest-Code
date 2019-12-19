#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int cnt[1007];
map<int, int> ans;

struct Point
{
    int x, y;

    Point() {}
    Point(int xx, int yy)
    {
        x = xx, y = yy;
    }

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    int operator^(const Point &b) const { return x * b.y - y * b.x; }
} p[1007];

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee)
    {
        s = ss, e = ee;
    }

    bool operator<(const Line &b) const { return s.x < b.s.x; }
} par[5007];

int relation(Point p, Line l) // 1点在线右侧，0在左侧
{
    return ((p - l.s) ^ (l.e - l.s)) > 0;
}

int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        memset(cnt, 0, sizeof(cnt));
        ans.clear();
        int m, x1, y1, x2, y2;
        scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
        par[0] = Line(Point(x1, y1), Point(x1, y2));
        par[n + 1] = Line(Point(x2, y1), Point(x2, y2));
        for (int i = 1; i <= n; i++)
        {
            int u, l;
            scanf("%d %d", &u, &l);
            par[i] = Line(Point(u, y1), Point(l, y2));
        }
        sort(par, par + n + 2);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            p[i] = Point(x, y);
        }
        for (int i = 0; i < m; i++)
        {
            int l = 0, r = n + 1;
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (relation(p[i], par[mid]) == 0)
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cnt[l]++;
        }
        for (int i = 0; i <= 1000; i++)
        {
            if (cnt[i] != 0)
            {
                ans[cnt[i]]++;
            }
        }
        printf("Box\n");
        for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++)
        {
            printf("%d: %d\n", it->first, it->second);
        }
    }
    return 0;
}