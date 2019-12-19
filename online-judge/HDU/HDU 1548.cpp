#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int vis[233], arr[233], step[233];
queue<int> q;

int bfs(int n, int st, int end)
{
    int dir[2] = {1, -1};
    vis[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int next = cur + dir[i] * arr[cur];
            if (next < 1 || next > n)
            {
                continue;
            }
            if (!vis[next])
            {
                step[next] = step[cur] + 1;
                vis[next] = 1;
                q.push(next);
            }
            if (next == end)
            {
                return step[next];
            }
        }
    }
    return -1;
}

int main()
{
    int n, st, end;
    while (cin >> n >> st >> end)
    {
        memset(vis, 0, sizeof(vis));
        memset(arr, 0, sizeof(arr));
        memset(step, 0, sizeof(step));
        while (!q.empty())
        {
            q.pop();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        if (st == end)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bfs(n, st, end) << endl;
        }
    }
    return 0;
}
