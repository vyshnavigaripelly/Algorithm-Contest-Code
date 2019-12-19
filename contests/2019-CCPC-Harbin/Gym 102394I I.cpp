#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int h[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &h[i]);
        }
        long long ans = 1, cnt = 0;
        if (h[1] != 0)
        {
            ans = 0;
        }
        else
        {
            for (int i = 2; i <= n; i++)
            {
                if (h[i] == 0 || h[i] >= n || h[i] < h[i - 1])
                {
                    ans = 0;
                    break;
                }
                if (h[i] != h[i - 1])
                {
                    ans = ans * 2 % mod;
                    cnt += h[i] - h[i - 1] - 1;
                }
                else
                {
                    ans = ans * cnt % mod;
                    cnt--;
                }
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}