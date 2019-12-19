#include <iostream>
#include <cstring>
using namespace std;

int bcj[10000];

int Find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = Find(bcj[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    bcj[x] += bcj[y];
    bcj[y] = x;
}

int Count(int x)
{
    x = Find(x);
    return -bcj[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n && n)
    {
        int m;
        cin >> m;
        memset(bcj, -1, sizeof(bcj));
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (bcj[i] < 0)
            {
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}