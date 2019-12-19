#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXSIZE = 102;

struct Node
{
    int a, b, op, step;
    Node *pre;
} stats[MAXSIZE][MAXSIZE];

int vis[MAXSIZE][MAXSIZE];
queue<Node> q;

void PrintPath(Node *cur)
{
    string strop[7] = {"", "FILL(1)", "DROP(1)", "POUR(1,2)", "FILL(2)", "DROP(2)", "POUR(2,1)"};
    if (cur->pre == NULL)
    {
        return;
    }
    PrintPath(cur->pre);
    cout << strop[cur->op] << endl;
}

void bfs(Node start, int maxa, int maxb, int c)
{
    vis[0][0] = 1;
    q.push(start);
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.a == c || cur.b == c)
        {
            cout << cur.step << endl;
            PrintPath(&cur);
            return;
        }
        for (int i = 1; i <= 6; i++)
        {
            Node next;
            if (i == 1) // FILL(1)
            {
                next.a = maxa;
                next.b = cur.b;
            }
            else if (i == 2) // DROP(1)
            {
                next.a = 0;
                next.b = cur.b;
            }
            else if (i == 3) // POUR(1,2)
            {
                if (cur.b + cur.a <= maxb)
                {
                    next.a = 0;
                    next.b = cur.a + cur.b;
                }
                else
                {
                    next.b = maxb;
                    next.a = cur.a - (maxb - cur.b);
                }
            }
            else if (i == 4) // FILL(2)
            {
                next.a = cur.a;
                next.b = maxb;
            }
            else if (i == 5) // DROP(2)
            {
                next.a = cur.a;
                next.b = 0;
            }
            else if (i == 6) // POUR(2,1)
            {
                if (cur.a + cur.b <= maxa)
                {
                    next.b = 0;
                    next.a = cur.b + cur.a;
                }
                else
                {
                    next.a = maxa;
                    next.b = cur.b - (maxa - cur.a);
                }
            }
            next.op = i;
            next.step = cur.step + 1;
            if (!vis[next.a][next.b])
            {
                next.pre = &stats[cur.a][cur.b];
                q.push(next);
                vis[next.a][next.b] = 1;
                stats[next.a][next.b] = next;
            }
        }
    }
    cout << "impossible" << endl;
}

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        memset(stats, 0, sizeof(stats));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        Node start = {0, 0, 0, 0, NULL};
        bfs(start, a, b, c);
    }
    return 0;
}
