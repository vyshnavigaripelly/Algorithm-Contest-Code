#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int arr[N], pos[N], f[N], d[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int len = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for (int i = 1; i <= n; i++)
        {
            d[i] = lower_bound(f + 1, f + 1 + len, arr[i]) - f;
            f[d[i]] = arr[i];
            if (d[i] > len)
                len = d[i];
        }
        for (int i = 1; i <= n; i++)
        {
            memset(pos, 0x3f, sizeof pos);
            pos[0] = -1;
            int sum = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                int tmp = d[j];
                if (pos[tmp - 1] < arr[j])
                    pos[tmp] = arr[j], sum ^= tmp * tmp;
                else
                    pos[tmp - 1] = arr[j], sum ^= (tmp - 1) * (tmp - 1);
            }
            printf("%d ", sum);
        }
    }
    return 0;
}