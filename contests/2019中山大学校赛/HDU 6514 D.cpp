#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        vector<vector<int>> mp(n + 6, vector<int>(m + 6));
        int p, q, x1, y1, x2, y2;
        scanf("%d", &p);
        while (p--)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            mp[x1][y1]++;
            mp[x2 + 1][y2 + 1]++;
            mp[x1][y2 + 1]--;
            mp[x2 + 1][y1]--;
        }
        for (int i = 1; i <= n + 5; i++)
        {
            for (int j = 1; j <= m + 5; j++)
            {
                mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n + 5; i++)
        {
            for (int j = 1; j <= m + 5; j++)
            {
                if (mp[i][j] > 1)
                {
                    mp[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n + 5; i++)
        {
            for (int j = 1; j <= m + 5; j++)
            {
                mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
            }
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int sum = mp[x2][y2] - mp[x2][y1 - 1] - mp[x1 - 1][y2] + mp[x1 - 1][y1 - 1];
            if (sum == (x2 - x1 + 1) * (y2 - y1 + 1))
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}