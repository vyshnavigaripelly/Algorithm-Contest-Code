#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

const double eps = 1e-8;

int n;
int vis[107];
double dis[107];
vector<pair<int, double>> edge[107];

int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) { x = xx, y = yy; }

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }

    double dist(const Point &b) const { return hypot(x - b.x, y - b.y); }
} wallPoint[20][4];

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

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
};

void addedge(int u, int v, double w)
{
    edge[u].push_back(make_pair(v, w));
    edge[v].push_back(make_pair(u, w));
}

void spfa(int stPoint)
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x4f, sizeof(dis));
    deque<int> q;
    q.push_front(stPoint);
    dis[stPoint] = 0;
    vis[stPoint] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop_front();
        vis[now] = 0;
        for (int i = 0; i < edge[now].size(); i++)
        {
            int v = edge[now][i].first;
            double w = edge[now][i].second;
            if (dis[v] > dis[now] + w)
            {
                dis[v] = dis[now] + w;
                if (vis[v])
                    continue;
                vis[v] = 1;
                if (q.empty())
                    q.push_back(v);
                else if (dis[q.front()] < dis[v])
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}

int check(Point start, Point end)
{
    Line line = Line(start, end);
    for (int i = 0; i < n; i++)
    {
        double xx = wallPoint[i][0].x;
        Line walls[3] = {
            Line(Point(xx, 0), Point(xx, wallPoint[i][0].y)),
            Line(Point(xx, wallPoint[i][1].y), Point(xx, wallPoint[i][2].y)),
            Line(Point(xx, wallPoint[i][3].y), Point(xx, 10))
        };
        for (int j = 0; j < 3; j++)
        {
            if (line.segcrossseg(walls[j]) == 2)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    while (~scanf("%d", &n) && n != -1)
    {
        for (int i = 0; i < 4 * n + 5; i++)
            edge[i].clear();
        for (int i = 0; i < n; i++)
        {
            double x, y;
            scanf("%lf", &x);
            for (int j = 0; j < 4; j++)
            {
                scanf("%lf", &y);
                wallPoint[i][j] = Point(x, y);
            }
        }
        // 0     [1 2 3 4] [5 6 7 8] ... [ i*4+(1..4) ] 4*n+1
        // start [ wall0 ] [ wall1 ] ... [    walli   ] end
        Point start = Point(0, 5),
              end = Point(10, 5);
        if (check(start, end))
            addedge(0, 4 * n + 1, 10);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Point cur = wallPoint[i][j];
                if (check(start, cur))
                    addedge(0, 4 * i + j + 1, start.dist(cur));
                if (check(cur, end))
                    addedge(4 * i + j + 1, 4 * n + 1, cur.dist(end));
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        Point a = wallPoint[i][k], b = wallPoint[j][l];
                        if (check(a, b))
                        {
                            addedge(4 * i + k + 1, 4 * j + l + 1, a.dist(b));
                        }
                    }
                }
            }
        }
        spfa(0);
        printf("%.2f\n", dis[4 * n + 1]);
    }
    return 0;
}