#include <iostream>

using namespace std;

int block[10][10], row[10][10], col[10][10], mp[10][10], flag = 0;

int blockid(int i, int j)
{
    int id = (i - 1) * 9 + j;
    int x = ((id - 1) / 27) * 3;
    int tmp = j % 9;
    if (!tmp)
        tmp = 9;
    tmp--;
    return x + (tmp / 3) + 1;
}

void dfs(int x, int y)
{
    if (y == 10)
    {
        x++;
        y = 1;
    }
    if (x == 10)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << endl;
        }
        flag = 1;
        return;
    }
    if (mp[x][y] == 0)
    {
        int id = blockid(x, y);
        for (int num = 1; num <= 9 && !flag; num++)
        {
            if (!row[x][num] && !col[y][num] && !block[id][num])
            {
                mp[x][y] = num;
                row[x][num] = 1;
                col[y][num] = 1;
                block[id][num] = 1;
                dfs(x, y + 1);
                block[id][num] = 0;
                row[x][num] = 0;
                col[y][num] = 0;
                mp[x][y] = 0;
            }
        }
        return;
    }
    else if (!flag)
    {
        dfs(x, y + 1);
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> mp[i][j];
            row[i][mp[i][j]] = 1;
            col[j][mp[i][j]] = 1;
            block[blockid(i, j)][mp[i][j]] = 1;
        }
    }
    dfs(1, 1);
    return 0;
}
