#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 25;

int w, h, sr, sc, er, ec, map[MAXN][MAXN], minstep;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool check(int r, int c)
{
    return (r >= 0 && r < h && c >= 0 && c < w);
}

void dfs(int r, int c, int step)
{
    if (step >= 10 || step > minstep)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextr = r, nextc = c, flag = 1;
        while (check(nextr, nextc) && flag)
        {
            if (map[nextr][nextc] == 0) // space, continue rolling
            {
                nextr += dir[i][0];
                nextc += dir[i][1];
            }
            else if (map[nextr][nextc] == 3) // goal
            {
                if (step + 1 < minstep)
                {
                    minstep = step + 1;
                }
                flag = 0;
            }
            else if (map[nextr][nextc] == 1) // block
            {
                if (nextr - dir[i][0] != r || nextc - dir[i][1] != c) // not blocked immediately
                {
                    map[nextr][nextc] = 0; // destroy block
                    dfs(nextr - dir[i][0], nextc - dir[i][1], step + 1);
                    map[nextr][nextc] = 1; // restore block
                }
                flag = 0;
            }
        }
    }
    return;
}

int main()
{
    while (cin >> w >> h && w && h)
    {
        memset(map, 0, sizeof(map));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 2)
                {
                    sr = i;
                    sc = j;
                }
            }
        }
        map[sr][sc] = 0;
        minstep = 99;
        dfs(sr, sc, 0);
        if (minstep > 10)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << minstep << endl;
        }
    }
    return 0;
}