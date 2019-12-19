#include <iostream>
using namespace std;

char mp[1007][1007];
int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

int check(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        if (mp[x + dir[i][0]][y + dir[i][1]] == '.')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i];
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (check(i, j))
            {
                for (int k = 0; k < 8; k++)
                {
                    if (mp[i + dir[k][0]][j + dir[k][1]] == '#')
                    {
                        mp[i + dir[k][0]][j + dir[k][1]] = 'X';
                        cnt--;
                    }
                }
            }
        }
    }
    // cout << cnt << endl;
    if (cnt == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}