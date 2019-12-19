#include <iostream>
#include <cstring>
using namespace std;

int dp[35][15];

void dfs(int row, int col, int state, int next)
{
    if (row == 3)
    {
        dp[col + 1][next] += dp[col][state];
        return;
    }
    if ((state & (1 << row)) > 0)
    {
        dfs(row + 1, col, state, next);
    }
    if ((state & (1 << row)) == 0) // place horizontal, 2 * 1
    {
        dfs(row + 1, col, state, next | (1 << row));
    }
    if (row + 1 < 3 && (state & (1 << row)) == 0 && (state & (1 << (row + 1))) == 0) // place vercial, 1 * 2
    {
        dfs(row + 2, col, state, next);
    }
}

int main()
{
    int n;
    while (cin >> n && n != -1)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                dfs(0, i, j, 0);
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}