#include <iostream>
#include <cstdio>

using namespace std;

char mp[57][57];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", mp[i] + 1);
    }
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 2; j <= n - 1; j++)
        {
            if (mp[i][j] == '.' && mp[i + 1][j - 1] == '.' && mp[i + 1][j] == '.' &&
                mp[i + 1][j + 1] == '.' && mp[i + 2][j] == '.')
            {
                mp[i][j] = mp[i + 1][j - 1] = mp[i + 1][j] = mp[i + 1][j + 1] = mp[i + 2][j] = '#';
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    puts(cnt == n * n ? "YES" : "NO");
    return 0;
}