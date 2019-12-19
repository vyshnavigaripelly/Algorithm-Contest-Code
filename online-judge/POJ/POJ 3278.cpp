#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 100000;

int vis[MAXN + 10];
int step[MAXN + 10];
queue<int> q;

int bfs(int n, int k)
{
    int loop[3] = {1, -1};
    vis[n] = 1;
    q.push(n);
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        loop[2] = pos;
        for (int i = 0; i < 3; i++)
        {
            int next = pos + loop[i];
            if (next < 0 || next > MAXN)
            {
                continue;
            }
            if (!vis[next])
            {
                step[next] = step[pos] + 1;
                vis[next] = 1;
                q.push(next);
            }
            if (next == k)
            {
                return step[next];
            }
        }
    }
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        memset(step, 0, sizeof(step));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        if (n >= k)
        {
            cout << n - k << endl;
        }
        else
        {
            cout << bfs(n, k) << endl;
        }
    }
    return 0;
}
