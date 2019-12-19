#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

const int N = 4e5 + 7;

map<int, int> mp;
int sum[N];

int main()
{
    int n, size, K;
    scanf("%d %d", &n, &size);
    for (int i = n; i >= 0; i--)
    {
        int tmp = (int)ceil(log2(i)) * n;
        if (tmp <= 8 * size)
        {
            K = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        mp[k]++;
    }
    if (mp.size() <= K)
    {
        puts("0");
    }
    else
    {
        int cnt = 0;
        for (auto i : mp)
        {
            cnt++;
            sum[cnt] = sum[cnt - 1] + i.second;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= cnt; i++)
        {
            int l = i, r = i + K - 1;
            if (r > cnt)
            {
                break;
            }
            ans = min(ans, sum[l - 1] + sum[cnt] - sum[r]);
        }
        printf("%d\n", ans);
    }
    return 0;
}