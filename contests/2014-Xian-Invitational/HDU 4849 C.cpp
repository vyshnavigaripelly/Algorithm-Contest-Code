#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define INF 0x3f3f3f3f
#define N 1007

using namespace std;

long long x[N * (N + 1)], y[N * (N + 1)], mp[N][N], d[N];
int inq[N], buc[1000007];
int n, m;

void SPFA()
{
    deque<int> Q;
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    inq[0] = 1;
    Q.push_front(0);
    while (!Q.empty())
    {
        int now = Q.front();
        inq[now] = 0;
        Q.pop_front();
        for (int i = 1; i < n; i++)
        {
            if (i == now)
                continue;
            int v = i, w = mp[now][i];
            if (d[v] > d[now] + w)
            {
                d[v] = d[now] + w;
                if (inq[v])
                    continue;
                inq[v] = 1;
                if (Q.size() == 0)
                    Q.push_back(v);
                else if (d[Q.front()] >= d[v])
                    Q.push_front(v);
                else
                    Q.push_back(v);
            }
        }
    }
}

int main()
{
    while (~scanf("%d %d %lld %lld %lld %lld", &n, &m, &x[0], &x[1], &y[0], &y[1]))
    {
        memset(buc, 0, sizeof(buc));
        for (int i = 2; i <= n * (n + 1); i++)
        {
            x[i] = (12345 + x[i - 1] * 23456 + x[i - 2] * 34567 + x[i - 1] * x[i - 2] * 45678) % 5837501;
            y[i] = (56789 + y[i - 1] * 67890 + y[i - 2] * 78901 + y[i - 1] * y[i - 2] * 89012) % 9860381;
        }
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                mp[i][j] = ((x[i * n + j] * 90123 + y[i * n + j]) % 8475871) + 1;
            }
        }
        SPFA();
        for (int i = 1; i <= n - 1; i++)
        {
            buc[d[i] % m]++;
        }
        for (int i = 0; i <= N * N; i++)
        {
            if (buc[i])
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
