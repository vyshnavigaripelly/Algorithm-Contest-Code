#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e7 + 7;

int sg[N], vis[N];

void maketable()
{
    for (int i = 1; i <= 100; i++)
    {
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < i; j++)
        {
            vis[sg[j]] = 1;
        }
        for (int j = 1; j <= i - 2; j++)
        {
            for (int k = j; k <= i - 2; k++)
            {
                int t = i - j - k;
                if (t <= 0)
                    continue;
                vis[sg[j] ^ sg[k] ^ sg[t]] = 1;
            }
        }
        int j = 0;
        while (vis[j])
            j++;
        sg[i] = j;
    }
    for (int i = 0; i <= 100; i++)
    {
        printf("%d : %d\n", i, sg[i]);
    }
}

int main()
{
    // maketable();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if ((tmp + 1) % 8 == 0)
            {
                ans ^= (tmp + 1);
            }
            else if (tmp % 8 == 0)
            {
                ans ^= (tmp - 1);
            }
            else
            {
                ans ^= tmp;
            }
        }
        puts(ans ? "First player wins." : "Second player wins.");
    }
    return 0;
}