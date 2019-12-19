#include <iostream>
#include <cstring>
using namespace std;

int bcj[30007], n, m, arr[30007];

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
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        memset(bcj, -1, sizeof(bcj));
        while (m--)
        {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                cin >> arr[i];
            }
            for (int i = 1; i < k; i++)
            {
                Union(arr[i], arr[i - 1]);
            }
        }
        cout << Count(0) << endl;
    }
    return 0;
}