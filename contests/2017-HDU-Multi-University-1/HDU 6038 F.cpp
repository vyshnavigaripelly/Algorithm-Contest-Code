#include <iostream>
#include <cstring>
#include <cstdio>

const int mod = 1e9 + 7;

using namespace std;

int n, m, cnt1, cnt2;
int a[100007], b[100007], visa[100007], visb[100007], loopa[100007], loopb[100007];

int main()
{
    int cas = 0;
    while (~scanf("%d%d", &n, &m))
    {
        memset(visa, 0, sizeof(visa));
        memset(visb, 0, sizeof(visb));
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        for (int i = 0; i < n; i++)
        {
            if (!visa[i])
            {
                int num = 0;
                for (int now = i; !visa[now]; now = a[now])
                {
                    num++;
                    visa[now] = 1;
                }
                loopa[cnt1++] = num;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (!visb[i])
            {
                int num = 0;
                for (int now = i; !visb[now]; now = b[now])
                {
                    num++;
                    visb[now] = 1;
                }
                loopb[cnt2++] = num;
            }
        }
        long long ans = 1;
        for (int i = 0; i < cnt1; i++)
        {
            long long tmp = 0;
            for (int j = 0; j < cnt2; j++)
            {
                if (loopa[i] % loopb[j])
                    continue;
                tmp = (tmp + loopb[j]) % mod;
            }
            ans = (ans * (tmp % mod)) % mod;
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}