#include <iostream>
#include <algorithm>

using namespace std;

int cnt[100007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    if (find(cnt + 1, cnt + n + 1, 2) == cnt + n + 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}