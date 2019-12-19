#include <iostream>
#include <cstring>
using namespace std;

int dir[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

int vis[30][30], path[50][2];
int p, q, done;

bool check(int r, int c)
{
    return (r >= 1 && r <= p && c >= 1 && c <= q && !vis[r][c] && !done);
}

void dfs(int r, int c, int step)
{
    path[step][0] = r;
    path[step][1] = c;
    if (step == p * q)
    {
        done = 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int nextr = r + dir[i][0];
        int nextc = c + dir[i][1];
        if (check(nextr, nextc))
        {
            vis[nextr][nextc] = 1;
            dfs(nextr, nextc, step + 1);
            vis[nextr][nextc] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    for (int cas = 1; cas <= n; cas++)
    {
        memset(vis, 0, sizeof(vis));
        memset(path, 0, sizeof(path));
        done = 0;
        cin >> p >> q;
        vis[1][1] = 1;
        dfs(1, 1, 1);
        cout << "Scenario #" << cas << ":" << endl;
        if (done)
        {
            for (int i = 1; i <= p * q; i++)
            {
                cout << char(path[i][1] + 'A' - 1) << path[i][0];
            }
        }
        else
        {
            cout << "impossible";
        }
        cout << endl
             << endl;
    }
    return 0;
}
