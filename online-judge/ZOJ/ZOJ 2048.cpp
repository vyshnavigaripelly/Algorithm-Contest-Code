#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 800; //最大点数
const int MAXM = 800 * 400; //最大边数
int F[MAXN]; //并查集使用
int num; //加入的边数

struct Edge
{
    int u, v;
    double w;
} edge[MAXM]; //存储边的信息，包括起点/终点/权值

struct Point
{
    int x, y;
} p[MAXN];

int tol; //边数，加边前赋值为0

void addedge(int u, int v, double w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}

double dist(Point a, Point b)
{
    return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}

bool cmp(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (F[x] < 0)
        return x;
    else
        return F[x] = find(F[x]);
}

int Union(int x, int y) //合并
{
    x = find(x); // 找到x和y的根节点
    y = find(y);
    if (x == y) // x，y在同一集合里，返回
        return 0;
    // F[x] += F[y]; // F[x]是根下的子节点即该集合的元素个数，以负数表示
    F[y] = x; // 将y指向x
    return 1;
}

void Kruskal(int n)
{
    sort(edge, edge + tol, cmp);
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (Union(u, v))
        {
            cout << u << ' ' << v << endl;
            num++;
        }
        if (num >= n - 1)
            break;
    }
    // if (num < n - 1)
    //     return -1; //不连通
    // else
    //     return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        tol = num = 0;
        memset(F, -1, sizeof(F));
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            if (Union(u, v))
            {
                num++;
            }
            // addedge(u, v, w);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (find(i) != find(j))
                {
                    addedge(i, j, dist(p[i], p[j]));
                }
            }
        }
        Kruskal(n);
        if (t)
        {
            cout << endl;
        }
    }
    return 0;
}