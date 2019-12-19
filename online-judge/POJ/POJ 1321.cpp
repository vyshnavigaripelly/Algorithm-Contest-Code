#include <iostream>
#include <cstring>
using namespace std;

char map[10][10];
int viscol[10], num, ans, n, k;

void dfs(int cur)
{
    if (num == k)
    {
        ans++;
        return;
    }
    if (cur >= n)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (viscol[i] == 0 && map[cur][i] == '#')
        {
            viscol[i] = 1;
            num++;
            dfs(cur + 1);
            viscol[i] = 0;
            num--;
        }
    }
    dfs(cur + 1);
    return;
}

int main()
{
    while (cin >> n >> k && n != -1 && k != -1)
    {
        memset(map, 0, sizeof(map));
        memset(viscol, 0, sizeof(viscol));
        num = 0;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
