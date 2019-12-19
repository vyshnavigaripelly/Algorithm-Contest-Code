#include <iostream>
#include <cstring>
using namespace std;

int parent[2007], relation[2007];

int Find(int x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    else
    {
        int tmp = parent[x];
        parent[x] = Find(parent[x]);
        relation[x] = (relation[x] + relation[tmp]) % 2;
        return parent[x];
    }
}

void Union(int a, int b)
{
    int x = Find(a), y = Find(b);
    parent[x] = y;
    relation[x] = (relation[a] + relation[b] + 1) % 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, m, a, b;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m, flag = 0;
        cin >> n >> m;
        memset(parent, -1, sizeof(parent));
        memset(relation, 0, sizeof(relation));
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (flag)
            {
                continue;
            }
            if (Find(a) == Find(b))
            {
                if (relation[a] == relation[b])
                {
                    flag = 1;
                }
            }
            else
            {
                Union(a, b);
            }
        }
        cout << "Scenario #" << cas << ":" << endl;
        if (flag)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }
        cout << endl;
    }
    return 0;
}