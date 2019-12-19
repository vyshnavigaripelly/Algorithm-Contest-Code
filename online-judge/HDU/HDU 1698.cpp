#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 定义
#define lson l, m, root << 1
#define rson m + 1, r, root << 1 | 1

const int maxn = 100007; // 元素总个数
int sum[maxn << 2]; // sum求和，minn最值
int lazy[maxn << 2]; // lazy为懒惰标记
int arr[maxn], n; // 存原数组数据下标[1,n]

// PushUp函数更新节点信息
void PushUp(int root)
{
    sum[root] = sum[root << 1] + sum[root << 1 | 1]; // 求和
}

// Build函数建树 Build(1,n,1);
void Build(int l, int r, int root) // l,r表示当前节点区间，root表示当前节点编号
{
    if (l == r) // 若到达叶节点
    {
        sum[root] = 1; // 储存数组值
        return;
    }
    int m = (l + r) >> 1;
    // 左右递归
    Build(l, m, root << 1);
    Build(m + 1, r, root << 1 | 1);
    // 更新信息
    PushUp(root);
}

// 下推
void PushDown(int root, int ln, int rn)
{
    // ln,rn为左子树，右子树的数字数量。
    if (lazy[root])
    {
        // 下推标记
        lazy[root << 1] = lazy[root];
        lazy[root << 1 | 1] = lazy[root];
        // 如果是维护区间和，则要乘上区间长度
        sum[root << 1] = lazy[root] * ln;
        sum[root << 1 | 1] = lazy[root] * rn;
        // 清除本节点标记
        lazy[root] = 0;
    }
}

// 区间修改 UpdateSection(L,R,num,1,n,1);
void UpdateSection(int L, int R, int num, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果本区间完全在操作区间[L,R]以内
    {
        lazy[root] = num; // 增加lazy标记，表示本区间的sum正确，子区间的sum仍需要根据lazy的值来调整
        sum[root] = num * (r - l + 1); // 更新数字和，向上保持正确
        return;
    }
    int m = (l + r) >> 1;
    PushDown(root, m - l + 1, r - m); // 下推标记
    // 这里判断左右子树跟[L,R]有无交集，有交集才递归
    if (L <= m)
        UpdateSection(L, R, num, l, m, root << 1);
    if (R > m)
        UpdateSection(L, R, num, m + 1, r, root << 1 | 1);
    PushUp(root); // 更新本节点信息
}

// 查询 ans=Query(L,R,1,n,1);
int Query(int L, int R, int l, int r, int root) // L,R表示操作区间，l,r表示当前节点区间，root表示当前节点编号
{
    if (L <= l && r <= R) // 如果区间[l,r]被[L,R]包含
    {
        return sum[root]; // 直接返回
    }
    int m = (l + r) >> 1;
    PushDown(root, m - l + 1, r - m); // 下推标记，否则sum可能不正确（仅区间查询）
    int ans = 0; // 累计答案
    if (L <= m)
    {
        ans += Query(L, R, l, m, root << 1); // 求和
    }
    if (R > m)
    {
        ans += Query(L, R, m + 1, r, root << 1 | 1);
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(lazy, 0, sizeof(lazy));
        memset(sum, 0, sizeof(sum));
        int n, q;
        scanf("%d %d", &n, &q);
        Build(1, n, 1);
        while (q--)
        {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            UpdateSection(l, r, k, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", cas, Query(1, n, 1, n, 1));
    }
    return 0;
}