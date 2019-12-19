#include <iostream>
#include <cstring>
using namespace std;

int bcj[50007], n, m;

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

    int cas = 1;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        memset(bcj, -1, sizeof(bcj));
        while (m--)
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
        cout << "Case " << cas << ": " << cnt << endl;
        cas++;
    }
    return 0;
}