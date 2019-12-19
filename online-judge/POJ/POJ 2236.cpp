#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int parent[1100], n, flag[1100];

struct Computer
{
    int x, y;
} arr[1100];

int Find(int x)
{
    if (parent[x] < 0)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    parent[x] += parent[y];
    parent[y] = x;
}

int Count(int x)
{
    x = Find(x);
    return -parent[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d;
    cin >> n >> d;
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    char op;
    while (cin >> op)
    {
        if (op == 'O')
        {
            int p;
            cin >> p;
            if (flag[p])
            {
                continue;
            }
            else
            {
                flag[p] = 1;
                for (int i = 1; i <= n; i++)
                {
                    int pa = Find(i), pb = Find(p);
                    double distsqr = pow(arr[i].x - arr[p].x, 2) + pow(arr[i].y - arr[p].y, 2);
                    if (flag[i] && distsqr <= d * d && pa != pb)
                    {
                        Union(i, p);
                    }
                }
            }
        }
        else if (op == 'S')
        {
            int p, q;
            cin >> p >> q;
            if (Find(p) == Find(q))
            {
                cout << "SUCCESS" << endl;
            }
            else
            {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}