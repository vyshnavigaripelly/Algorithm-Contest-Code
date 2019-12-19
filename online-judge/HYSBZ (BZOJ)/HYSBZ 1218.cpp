#include <iostream>
#include <algorithm>

using namespace std;

int mp[5007][5007];

int main()
{
    int n, r;
    cin >> n >> r;
    int maxx = r, maxy = r;
    while (n--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        mp[x + 1][y + 1] = v;
        maxx = max(maxx, x + 1);
        maxy = max(maxy, y + 1);
    }
    for (int i = 1; i <= maxx; i++)
    {
        for (int j = 1; j <= maxy; j++)
        {
            mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = r; i <= maxx; i++)
    {
        for (int j = r; j <= maxy; j++)
        {
            ans = max(ans, mp[i][j] - mp[i - r][j] - mp[i][j - r] + mp[i - r][j - r]);
        }
    }
    cout << ans << endl;
    return 0;
}