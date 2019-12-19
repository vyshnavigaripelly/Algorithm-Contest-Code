#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 110; //最大点数
const int MAXM = 10007; //最大边数
int F[MAXN]; //并查集使用

struct Point
{
    double x, y;
} p[107];

double dist(const Point &a, const Point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

struct Edge
{
    int u, v;
    double w;
} edge[MAXM]; //存储边的信息，包括起点/终点/权值

int tol; //边数，加边前赋值为0

void addedge(int u, int v, double w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (F[x] == -1)
        return x;
    else
        return F[x] = find(F[x]);
}

double Kruskal(int n) //传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(F, -1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0; //计算加入的边数
    double ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        double w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2)
        {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt < n - 1)
        return -1; //不连通
    else
        return ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        tol = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                addedge(i, j, dist(p[i], p[j]));
            }
        }
        printf("%.2f\n", Kruskal(n));
    }
    return 0;
}