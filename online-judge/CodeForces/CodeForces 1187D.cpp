#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 3e5 + 7;
const int INF = (1 << 30) - 1;

int a[N], b[N];
queue<int> pos[N];

struct SegTree
{
    int l, r;
    int min;
} tr[N << 2];

void pushup(int root)
{
    tr[root].min = min(tr[lson].min, tr[rson].min);
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].min = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int pos)
{
    if (tr[root].l == tr[root].r)
    {
        tr[root].min = INF;
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
    {
        update(lson, pos);
    }
    else
    {
        update(rson, pos);
    }
    pushup(root);
}

int query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        return tr[root].min;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = INF;
    if (l <= mid)
    {
        ans = min(ans, query(lson, l, r));
    }
    if (r > mid)
    {
        ans = min(ans, query(rson, l, r));
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            while (!pos[i].empty())
                pos[i].pop();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]].push(i);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!pos[b[i]].empty())
            {
                int posnow = pos[b[i]].front();
                pos[b[i]].pop();
                int minn = query(1, 1, posnow);
                if (minn < b[i])
                {
                    flag = 0;
                    break;
                }
                else
                {
                    update(1, posnow);
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}