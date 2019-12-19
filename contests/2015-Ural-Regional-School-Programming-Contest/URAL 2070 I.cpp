#include <bits/stdc++.h>

using namespace std;

int maxn = 1e6 + 7;
const int N = 1e6 + 7;
int prime[N];
bool notprime[N];

int main()
{
    long long l, r;
    cin >> l >> r;
    if (r - l == 0 && l == 1)
        cout << 1 << endl;
    else
    {
        long long ans = 0;
        if (l == 1)
        {
            l++, ans++;
        }
        for (int i = 2; i <= maxn; i++)
        {
            if (!prime[i])
                prime[++prime[0]] = i;
            for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++)
            {
                prime[prime[j] * i] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
        notprime[0] = notprime[1] = true;
        for (int i = 2; i < maxn; i++)
            if (!notprime[i])
            {
                if (i > maxn / i)
                    continue;
                for (int j = i * i; j < maxn; j += i)
                    notprime[j] = true;
            }

        ans += r - l + 1;
        for (int i = 1; i <= prime[0]; i++)
        {
            long long tmp = 1;
            int cnt = 0;
            for (tmp = 1; tmp < l; cnt++)
            {
                tmp *= prime[i];
            }
            for (; tmp <= r; cnt++)
            {
                if (cnt > 1 && !notprime[cnt + 1])
                    ans--;
                tmp *= prime[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}