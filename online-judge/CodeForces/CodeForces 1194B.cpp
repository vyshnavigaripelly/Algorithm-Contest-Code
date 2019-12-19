#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string mp[50007];
int cntrow[50007], cntcol[50007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(cntrow, 0, sizeof(cntrow));
        memset(cntcol, 0, sizeof(cntcol));
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            cin >> mp[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mp[i][j] == '.')
                {
                    cntrow[i]++;
                    cntcol[j]++;
                }
            }
        }
        int ans = 1e5;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = min(ans, cntrow[i] + cntcol[j] - (mp[i][j] == '.'));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}