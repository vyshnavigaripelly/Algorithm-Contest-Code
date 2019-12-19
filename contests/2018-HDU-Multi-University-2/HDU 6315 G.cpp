#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define lson l, m, root << 1
#define rson m + 1, r, root << 1 | 1

const int maxn = 100007;
int sum[maxn << 2];
int maxa[maxn << 2], minb[maxn << 2];
int lazy[maxn << 2];
int arr[maxn], n;

void PushUp(int root)
{
    sum[root] = sum[root << 1] + sum[root << 1 | 1];
    minb[root] = min(minb[root << 1], minb[root << 1 | 1]);
    maxa[root] = max(maxa[root << 1], maxa[root << 1 | 1]);
}

void Build(int l, int r, int root)
{
    if (l == r)
    {
        minb[root] = arr[l];
        sum[root] = 0;
        maxa[root] = 0;
        return;
    }
    int m = (l + r) >> 1;
    Build(l, m, root << 1);
    Build(m + 1, r, root << 1 | 1);
    PushUp(root);
}

// 下推
void PushDown(int root)
{
    if (lazy[root])
    {
        lazy[root << 1] += lazy[root];
        lazy[root << 1 | 1] += lazy[root];
        maxa[root << 1] += lazy[root];
        maxa[root << 1 | 1] += lazy[root];
        lazy[root] = 0;
    }
}

// 区间修改 UpdateSection(L,R,num,1,n,1);
void UpdateSection(int L, int R, int num, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果本区间完全在操作区间[L,R]以内
    {
        maxa[root]++;
        if (maxa[root] < minb[root])
        {
            lazy[root]++;
            return;
        }
        if (maxa[root] >= minb[root] && l == r)
        {
            sum[root]++;
            minb[root] += arr[l];
            return;
        }
    }
    int m = (l + r) >> 1;
    PushDown(root);
    if (L <= m)
        UpdateSection(L, R, num, l, m, root << 1);
    if (R > m)
        UpdateSection(L, R, num, m + 1, r, root << 1 | 1);
    PushUp(root);
}

// 查询 ans=Query(L,R,1,n,1);
int Query(int L, int R, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果区间[l,r]被[L,R]包含
    {
        return sum[root];
    }
    int m = (l + r) >> 1;
    PushDown(root);
    int ans = 0;
    if (L <= m)
    {
        ans += Query(L, R, l, m, root << 1);
    }
    if (R > m)
    {
        ans += Query(L, R, m + 1, r, root << 1 | 1);
    }
    return ans;
}

int main()
{
    int n, q;
    while (~scanf("%d %d", &n, &q))
    {
        memset(lazy, 0, sizeof(lazy));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        Build(1, n, 1);
        while (q--)
        {
            int l, r;
            char s[10];
            scanf("%s %d %d", s, &l, &r);
            if (s[0] == 'a')
            {
                UpdateSection(l, r, 1, 1, n, 1);
            }
            else
            {
                printf("%d\n", Query(l, r, 1, n, 1));
            }
        }
    }
    return 0;
}