#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int vis[1000007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        int n, ans;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
        {
            int k;
            scanf("%d", &k);
            vis[k]++;
            if (vis[k] > 1)
            {
                ans = k;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}