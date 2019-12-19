#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 107;

int w[N][N], n;
int choice[N];
long long ans = -1;

void dfs(int len, int now, long long cnt)
{
    if (len == n / 2)
    {
        ans = max(ans, cnt);
        return;
    }
    if (now > n || (len + (n - now + 1) < n / 2))
        return;
    choice[now] = 1;
    long long tmp = cnt;
    for (int i = 1; i <= n; i++)
    {
        if (choice[i])
            tmp -= w[i][now];
        else
            tmp += w[i][now];
    }
    dfs(len + 1, now + 1, tmp);
    choice[now] = 0;
    dfs(len, now + 1, cnt);
}

int main()
{
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    dfs(0, 1, 0);
    cout << ans << endl;
    return 0;
}