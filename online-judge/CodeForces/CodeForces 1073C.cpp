#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int dis[200007][2];
int n, endx, endy;

int check(int len)
{
    for (int i = 1; i <= n - len + 1; i++)
    {
        int x = dis[n][0] - dis[i + len - 1][0] + dis[i - 1][0];
        int y = dis[n][1] - dis[i + len - 1][1] + dis[i - 1][1];
        int xx = endx - x, yy = endy - y;
        if (abs(xx) + abs(yy) <= len && (len - abs(xx) - abs(yy)) % 2 == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s;
    cin >> n >> s >> endx >> endy;
    for (int i = 1; i <= s.length(); i++)
    {
        dis[i][0] = dis[i - 1][0] + (s[i - 1] == 'R' ? 1 : (s[i - 1] == 'L' ? -1 : 0));
        dis[i][1] = dis[i - 1][1] + (s[i - 1] == 'U' ? 1 : (s[i - 1] == 'D' ? -1 : 0));
    }
    int l = 0, r = n, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}