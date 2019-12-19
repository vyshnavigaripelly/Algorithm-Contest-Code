#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 50007;
int _min[maxn << 2], _max[maxn << 2];
int arr[maxn], n;

// PushUp函数更新节点信息
void PushUp(int root)
{
    _min[root] = min(_min[root << 1], _min[root << 1 | 1]);
    _max[root] = max(_max[root << 1], _max[root << 1 | 1]);
}

// Build函数建树 Build(1,n,1);
void Build(int l, int r, int root) // l,r表示当前节点区间，root表示当前节点编号
{
    if (l == r) // 若到达叶节点
    {
        _min[root] = _max[root] = arr[l]; // 储存数组值
        return;
    }
    int m = (l + r) >> 1;
    // 左右递归
    Build(l, m, root << 1);
    Build(m + 1, r, root << 1 | 1);
    // 更新信息
    PushUp(root);
}

// 查询 ans=Query(L,R,1,n,1);
int Query(int L, int R, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果区间[l,r]被[L,R]包含
    {
        return _min[root]; // 直接返回
    }
    int m = (l + r) >> 1;
    int ans = 0x3f3f3f3f; // 累计答案
    if (L <= m)
    {
        ans = min(ans, Query(L, R, l, m, root << 1));
    }
    if (R > m)
    {
        ans = min(ans, Query(L, R, m + 1, r, root << 1 | 1));
    }
    return ans;
}

int Query2(int L, int R, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果区间[l,r]被[L,R]包含
    {
        return _max[root]; // 直接返回
    }
    int m = (l + r) >> 1;
    int ans = 0; // 累计答案
    if (L <= m)
    {
        ans = max(ans, Query2(L, R, l, m, root << 1)); // 求最小值
    }
    if (R > m)
    {
        ans = max(ans, Query2(L, R, m + 1, r, root << 1 | 1));
    }
    return ans;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Build(1, n, 1);
    while (q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", Query2(a, b, 1, n, 1) - Query(a, b, 1, n, 1));
    }
    return 0;
}
