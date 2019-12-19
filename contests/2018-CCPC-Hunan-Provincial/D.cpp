#include <iostream>
#include <cstring>

using namespace std;

const int N = 1007;

char mp[N][N];
int used[N][N];
int n, m;

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(used[i], 0, (m + 2) * sizeof(int));
            scanf("%s", &mp[i][1]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (used[i][j])
                    continue;
                if (mp[i][j] == '^')
                {
                    int dx = i + 1, dy1 = j - 1, dy2 = j + 1;
                    if (!used[dx][dy1] && !used[dx][dy2] && mp[dx][dy1] == 'v' && mp[dx][dy2] == 'v')
                    {
                        used[i][j] = used[dx][dy1] = used[dx][dy2] = 1;
                        ans++;
                    }
                    else
                    {
                        dy1 = j + 1, dy2 = j + 2;
                        if (!used[dx][dy1] && !used[i][dy2] && mp[dx][dy1] == 'v' && mp[i][dy2] == '^')
                        {
                            used[i][j] = used[dx][dy1] = used[i][dy2] = 1;
                            ans++;
                        }
                    }
                }
                else if (mp[i][j] == 'v')
                {
                    int dx = i - 1, dy1 = j - 1, dy2 = j + 1;
                    if (!used[dx][dy1] && !used[dx][dy2] && mp[dx][dy1] == '^' && mp[dx][dy2] == '^')
                    {
                        used[i][j] = used[dx][dy1] = used[dx][dy2] = 1;
                        ans++;
                    }
                    else
                    {
                        dy1 = j + 1, dy2 = j + 2;
                        if (!used[dx][dy1] && !used[i][dy2] && mp[dx][dy1] == '^' && mp[i][dy2] == 'v')
                        {
                            used[i][j] = used[dx][dy1] = used[i][dy2] = 1;
                            ans++;
                        }
                    }
                }
                else if (mp[i][j] == '<')
                {
                    int dy = j + 1, dx1 = i - 1, dx2 = i + 1;
                    if (!used[dx1][dy] && !used[dx2][dy] && mp[dx1][dy] == '>' && mp[dx2][dy] == '>')
                    {
                        used[i][j] = used[dx1][dy] = used[dx2][dy] = 1;
                        ans++;
                    }
                    else
                    {
                        dx1 = i + 1, dx2 = i + 2;
                        if (!used[dx1][dy] && !used[dx2][j] && mp[dx1][dy] == '>' && mp[dx2][j] == '<')
                        {
                            used[i][j] = used[dx1][dy] = used[dx2][j] = 1;
                            ans++;
                        }
                    }
                }
                else
                {
                    int dy = j - 1, dx1 = i - 1, dx2 = i + 1;
                    if (!used[dx1][dy] && !used[dx2][dy] && mp[dx1][dy] == '<' && mp[dx2][dy] == '<')
                    {
                        used[i][j] = used[dx1][dy] = used[dx2][dy] = 1;
                        ans++;
                    }
                    else
                    {
                        dx1 = i + 1, dx2 = i + 2;
                        if (!used[dx1][dy] && !used[dx2][j] && mp[dx1][dy] == '<' && mp[dx2][j] == '>')
                        {
                            used[i][j] = used[dx1][dy] = used[dx2][j] = 1;
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
        {
            memset(mp[i], 0, (m + 1) * sizeof(char));
        }
    }
    return 0;
}