#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e6 + 7;
const int maxn = (1 << 20) - 1;

int SG[N], vis[N];

void sg()
{
    for (int i = 1; i <= maxn; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i & (1 << j))
            {
                int now = i ^ (1 << j);
                for (int k = j - 1; k >= 0; k--)
                {
                    if (!(now & (1 << k)))
                    {
                        int v = now ^ (1 << k);
                        vis[SG[v]] = 1;
                        break;
                    }
                }
            }
        }
        for (int j = 0; j < 20; j++)
        {
            if (!vis[j])
            {
                SG[i] = j;
                break;
            }
        }
        for (int j = 0; j < 20; j++)
        {
            vis[j] = 0;
        }
    }
}

int main()
{
    sg();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int nn;
            scanf("%d", &nn);
            int tmp, tar = 0;
            for (int i = 0; i < nn; i++)
            {
                scanf("%d", &tmp);
                tar |= (1 << (20 - tmp));
            }
            ans ^= SG[tar];
        }
        if (ans == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}