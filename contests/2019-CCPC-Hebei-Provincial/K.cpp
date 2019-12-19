#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

map<string, int> food;
map<int, string> order;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int k;
        cin >> s >> k;
        food[s] += k;
        order[i] = s;
    }
    int flag = 1;
    while (m--)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string a;
            int t;
            cin >> a >> t;
            if (food[a] < t)
            {
                flag = 0;
            }
            food[a] -= t;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (auto i : order)
        {
            if (food[i.second] > 0)
            {
                cout << i.second << ' ' << food[i.second] << endl;
            }
        }
    }
    else

    {
        cout << "NO" << endl;
    }
    return 0;
}