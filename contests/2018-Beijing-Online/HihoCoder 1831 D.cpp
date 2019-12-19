#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e6 + 7;

int a[N], b[N], st[N];
long long v[N];
queue<int> q;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c;
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            v[i] = a[i] - b[i];
        }
        long long now = c;
        int nowpos = 1, pos = -1;
        while (true)
        {
            if (now + v[nowpos] >= 0)
            {
                q.push(nowpos);
                now += v[nowpos];
                nowpos++;
                if (nowpos > n)
                {
                    nowpos = 1;
                }
                if (q.size() >= n)
                {
                    pos = q.front();
                    break;
                }
            }
            else
            {
                if (q.size())
                {
                    if (st[q.front() + 1])
                    {
                        break;
                    }
                    st[q.front() + 1] = 1;
                    now -= v[q.front()];
                    q.pop();
                }
                else
                {
                    now = c;
                    nowpos++;
                    if (st[nowpos])
                    {
                        break;
                    }
                    st[nowpos] = 1;
                }
            }
        }
        printf("%d\n", pos);
        while (q.size())
        {
            q.pop();
        }
        memset(st, 0, sizeof(st));
    }
    return 0;
}