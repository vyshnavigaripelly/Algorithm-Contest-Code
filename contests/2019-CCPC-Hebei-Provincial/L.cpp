#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <functional>

using namespace std;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, str[2507], cnt, flag, mp[57][57];
vector<pair<int, int>> first[10];

void dfs(int x, int y, int pos)
{
    if (pos == cnt)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < 4 && !flag; i++)
    {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (dx > 0 && dx <= n && dy > 0 && dy <= n && mp[dx][dy] == (str[pos] - '0'))
        {
            dfs(dx, dy, pos + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &mp[i][j]);
            first[mp[i][j]].push_back(make_pair(i, j));
        }
    }
    long long tar = 0;
    while (1)
    {
        flag = 0;
        long long tmp = tar;
        cnt = 0;
        do
        {
            str[cnt] = tmp % 10 + '0';
            cnt++;
            tmp /= 10;
        } while (tmp);
        reverse(str, str + cnt);
        str[cnt] = '\0';
        for (int i = 0; i < first[str[0] - '0'].size() && !flag; i++)
        {
            int x = first[str[0] - '0'][i].first, y = first[str[0] - '0'][i].second;
            dfs(x, y, 1);
        }
        if (!flag)
        {
            printf("%lld\n", tar);
            return 0;
        }
        tar++;
    }
    return 0;
}