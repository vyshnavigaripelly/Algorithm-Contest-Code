#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4e5 + 7;

int x[N], y[N];
int cntx, cnty;

struct node
{
    int y0, y1, x0, x1, id;

    node() {}

    node(int _x0, int _y0, int _x1, int _y1)
    {
        x0 = _x0, y0 = _y0, x1 = _x1, y1 = _y1;
        if (x0 > x1)
            swap(x0, x1);
        if (y0 > y1)
            swap(y0, y1);
    }

    bool operator<(const node &b) const
    {
        if (id != b.id)
            return id < b.id;
        return y0 < b.y0;
    }
} p[N];

struct BIT
{
#define lowbit(x) (x & (-x))
    int b[N];

    void init()
    {
        memset(b, 0, sizeof(b));
    }

    void update(int x, int v)
    {
        while (x < N)
        {
            b[x] += v;
            x += lowbit(x);
        }
    }

    int sum(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += b[x];
            x -= lowbit(x);
        }
        return ans;
    }
} bit;

struct Node
{
    int x, y, v;

    bool operator<(const Node &b) const
    {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
} a[N];

long long query(int l, int r)
{
    return bit.sum(r) - bit.sum(l - 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int X, Y, n;
        bit.init();
        scanf("%d %d %d", &X, &Y, &n);
        int totx = 0, toty = 0;
        for (int i = 1; i <= n; i++)
        {
            int x0, y0, x1, y1;
            char dir[4];
            scanf("%d %d %s", &x0, &y0, dir);
            if (dir[0] == 'U')
            {
                x1 = x0, y1 = Y;
            }
            else if (dir[0] == 'L')
            {
                x1 = 0, y1 = y0;
            }
            else if (dir[0] == 'R')
            {
                x1 = X, y1 = y0;
            }
            else
            {
                x1 = x0, y1 = 0;
            }
            x[totx++] = x0, x[totx++] = x1;
            y[toty++] = y0, y[toty++] = y1;
            p[i] = node(x0, y0, x1, y1);
            if (x0 == x1)
                p[i].id = 0;
            else
                p[i].id = 1;
        }
        sort(x, x + 2 * n);
        sort(y, y + 2 * n);
        cntx = unique(x, x + 2 * n) - x;
        cnty = unique(y, y + 2 * n) - y;
        for (int i = 1; i <= n; i++)
        {
            p[i].x0 = lower_bound(x, x + cntx, p[i].x0) - x + 1;
            p[i].y0 = lower_bound(y, y + cnty, p[i].y0) - y + 1;
            p[i].x1 = lower_bound(x, x + cntx, p[i].x1) - x + 1;
            p[i].y1 = lower_bound(y, y + cnty, p[i].y1) - y + 1;
        }
        sort(p + 1, p + n + 1);
        int pos = 1, res = 0;
        while (p[pos].id == 0 && pos <= n)
        {
            a[res].v = 1, a[res].x = p[pos].x0, a[res].y = p[pos].y0, res++;
            a[res].v = -1, a[res].x = p[pos].x0, a[res].y = p[pos].y1 + 1, res++;
            pos++;
        }
        sort(a, a + res);
        long long ans = 0;
        for (int i = 1, j = pos, k = 0; i <= cnty + 1; i++)
        {
            while (a[k].y == i && k < res)
            {
                bit.update(a[k].x, a[k].v);
                k++;
            }
            while (p[j].y0 == i && j <= n)
            {
                ans += query(p[j].x0, p[j].x1);
                j++;
            }
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}