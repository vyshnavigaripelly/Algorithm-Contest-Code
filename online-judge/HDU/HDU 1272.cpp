#include <iostream>
#include <cstring>
using namespace std;

int bcj[100007], vis[100007];

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
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
        {
            break;
        }
        if (a == 0 & b == 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        int flag = 1;
        memset(bcj, -1, sizeof(bcj));
        memset(vis, 0, sizeof(vis));
        do
        {
            vis[a] = vis[b] = 1;
            if (Find(a) == Find(b))
            {
                flag = 0;
            }
            Union(a, b);
        } while (cin >> a >> b && a && b);
        int cnt = 0;
        for (int i = 1; i <= 100000; i++)
        {
            if (vis[i] && bcj[i] < 0)
            {
                cnt++;
            }
        }
        if (flag && cnt == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}