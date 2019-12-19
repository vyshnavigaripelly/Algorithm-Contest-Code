#include <iostream>
#include <algorithm>

using namespace std;

const unsigned long long mod = 1e9 + 7;

unsigned long long k1, k2;
int fa[100007], n;

struct node
{
    int u, v;
    unsigned long long w;
} edge[100007];

int Find(int x)
{
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

int cmp(const node &a, const node &b)
{
    return a.w < b.w;
}

unsigned long long kruskal()
{
    int cnt = 0;
    unsigned long long ans = 0;
    for (int i = 1; i <= 100000; i++)
    {
        int u = Find(edge[i].u);
        int v = Find(edge[i].v);
        if (u != v)
        {
            ans += edge[i].w;
            ans %= mod;
            fa[u] = v;
            cnt++;
        }
        if (cnt == n - 1)
        {
            return ans % mod;
        }
    }
    return 0;
}

unsigned long long fun()
{
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return (k2 + k4);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m >> k1 >> k2;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; ++i)
        {
            int u = fun() % n + 1;
            int v = fun() % n + 1;
            unsigned long long w = fun();
            edge[i].u = u;
            edge[i].v = v;
            edge[i].w = w;
        }
        sort(edge + 1, edge + 1 + m, cmp);
        cout << kruskal() << endl;
    }
    return 0;
}