#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

const int dir[8][2] = {0, 1, 0, -1, 1, 0, 1, 1, 1, -1, -1, 0, -1, 1, -1, -1};
const double eps = 1e-8;

int n, vis[37][37];
char mp[37][37];
double px1, py1, px2, py2, px3, py3;
queue<pair<int, int>> q;

int sgn(double x)
{
    if ((fabs(x) < eps))
        return 0;
    return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;

    Point() {}
    Point(double xx, double yy) { x = xx, y = yy; }

    bool operator==(Point b) const { return sgn(x - b.x) == 0 && sgn(y - b.y) == 0; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
} pa, pb, pc;

struct Line
{
    Point s, e;

    Line() {}
    Line(Point ss, Point ee) { s = ss, e = ee; }

    bool pointonseg(Point p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
    }

    int segcrossseg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s)),
            d2 = sgn((e - s) ^ (v.e - s)),
            d3 = sgn((v.e - v.s) ^ (s - v.s)),
            d4 = sgn((v.e - v.s) ^ (e - v.s));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)
            return 2;
        return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
               (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
               (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
               (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
} a, b, c;

struct Polygon
{
    int n;
    Point p[3];
    Line l[3];

    void add(Point q) { p[n++] = q; }

    void getline()
    {
        for (int i = 0; i < n; i++)
            l[i] = Line(p[i], p[(i + 1) % n]);
    }

    int relationpoint(Point q)
    {
        for (int i = 0; i < n; i++)
            if (p[i] == q)
                return 3;
        getline();
        for (int i = 0; i < n; i++)
            if (l[i].pointonseg(q))
                return 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n,
                k = sgn((q - p[j]) ^ (p[i] - p[j])),
                u = sgn(p[i].y - q.y),
                v = sgn(p[j].y - q.y);
            if (k > 0 && u < 0 && v >= 0)
                cnt++;
            if (k < 0 && v < 0 && u >= 0)
                cnt--;
        }
        return cnt != 0;
    }
} tri;

int check(int X1, int Y1, int X2, int Y2) //X1Y1是起始点,X2Y2是终止点
{
    Line p = Line(Point(X1, Y1), Point(X2, Y2));
    if (!(a.segcrossseg(p) != 2 && b.segcrossseg(p) != 2 && c.segcrossseg(p) != 2))
    {
        return 0;
    }
    for (int i = 1; i <= 100; i++)
    {
        if (tri.relationpoint(Point(X1 + (X2 - X1) * i * 0.01, Y1 + (Y2 - Y1) * i * 0.01)) == 1)
        {
            return 0;
        }
    }
    return 1;
}

void bfs()
{
    while (q.size())
    {
        q.pop();
    }
    q.push(make_pair(n - 1, 0));
    vis[n - 1][0] = 1;
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (now.first == 0 && now.second == (n - 1))
        {
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int dx = now.first + dir[i][0];
            int dy = now.second + dir[i][1];
            if (mp[dx][dy] == '#' || vis[dx][dy] ||
                dx < 0 || dx >= n || dy < 0 || dy >= n ||
                !(check(now.first, now.second, dx, dy)))
            {
                continue;
            }
            vis[dx][dy] = vis[now.first][now.second] + 1;
            q.push(make_pair(dx, dy));
        }
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        tri.n = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%lf %lf %lf %lf %lf %lf", &px1, &py1, &px2, &py2, &px3, &py3);
        pa = Point(n - 1 - py1, px1);
        pb = Point(n - 1 - py2, px2);
        pc = Point(n - 1 - py3, px3);
        a = Line(pa, pb);
        b = Line(pb, pc);
        c = Line(pc, pa);
        tri.add(pa);
        tri.add(pb);
        tri.add(pc);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
        }
        bfs();
        printf("%d\n", vis[0][n - 1] - 1);
    }
    return 0;
}