#include <iostream>
#include <cstring>
using namespace std;

int bcj[10000];

int Find(int x)
{
    if (bcj[x] < 0) //X是根节点，返回下标X
        return x;
    return bcj[x] = Find(bcj[x]); // 找X指向的下一个点，路径压缩将经过的每个点指向根
}

void Union(int x, int y) //合并
{
    x = Find(x); // 找到x和y的根节点
    y = Find(y);
    if (x == y) // x，y在同一集合里，返回
        return;
    bcj[x] += bcj[y]; // bcj[x]是根下的子节点即该集合的元素个数，以负数表示
    bcj[y] = x; // 将y指向x
}

int Count(int x) // 查找该集合元素个数
{
    x = Find(x);
    return -bcj[x];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        memset(bcj, -1, sizeof(bcj));
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (bcj[i] < 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}