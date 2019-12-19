#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char map[105][105];

int main()
{
    memset(map, '.', sizeof(map));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    int flag = 1;
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (isdigit(map[i][j]))
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    if (map[i + dir[k][0]][j + dir[k][1]] == '*')
                    {
                        cnt++;
                    }
                }
                if (cnt != map[i][j] - '0')
                {
                    flag = 0;
                    break;
                }
            }
            else if (map[i][j] == '.')
            {
                for (int k = 0; k < 8; k++)
                {
                    if (map[i + dir[k][0]][j + dir[k][1]] == '*')
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
