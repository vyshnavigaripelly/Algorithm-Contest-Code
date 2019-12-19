#include <iostream>
#include <cstring>
using namespace std;

#define maxn 1007
int A[102], n = 102, N; //原数组,n为原数组元素个数 ,N为扩充元素个数
int Sum[maxn << 2]; //区间和
int Add[maxn << 2]; //懒惰标记

void Build(int n)
{
    //计算N的值
    N = 1;
    while (N < n + 2)
        N <<= 1;
    //更新叶节点
    for (int i = 1; i <= n; ++i)
        Sum[N + i] = A[i]; //原数组下标+N=存储下标
    //更新非叶节点
    for (int i = N - 1; i > 0; --i)
    {
        //更新所有非叶节点的统计信息
        Sum[i] = Sum[i << 1] + Sum[i << 1 | 1];
        //清空所有非叶节点的Add标记
        Add[i] = 0;
    }
}

void Update(int L, int C)
{
    for (int s = N + L; s; s >>= 1)
    {
        Sum[s] += C;
    }
}

int Query(int L, int R)
{
    int ANS = 0;
    for (int s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
    {
        if (~s & 1)
            ANS += Sum[s ^ 1];
        if (t & 1)
            ANS += Sum[t ^ 1];
    }
    return ANS;
}

int main()
{
    int t;
    while (cin >> t)
    {
        memset(A, 0, sizeof(A));
        memset(Sum, 0, sizeof(Sum));
        memset(Add, 0, sizeof(Add));
        while (t--)
        {
            int k;
            cin >> k;
            A[k + 1]++;
        }
        Build(102);
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << Query(l + 1, r + 1) << endl;
        }
    }
    return 0;
}
