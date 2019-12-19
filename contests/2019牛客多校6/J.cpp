#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;
long long sumq[N];
long long val[N][N], dp[N][N];
long long num[N];
long long n, m, t, cnt = 0;

struct ST
{
    long long f[N][20];

    void st(int cnt)
    {
        for (int i = 1; i <= m + 1; i++)
        {
            f[i][0] = val[cnt][i - 1];
        }
        int t = log(m + 1) / log(2) + 1;
        for (int j = 1; j < t; j++)
        {
            for (int i = 1; i <= m + 1 - (1 << j) + 1; i++)
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    long long query_max(int l, int r)
    {
        l++, r++;
        int k = log(r - l + 1) / log(2);

        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
ST st[1007];

int main()
{
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cnt = 0;
        long long sum = 0, ans = 0;
        scanf("%lld %lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            num[i] = 0;
            val[i][0] = 0;
            for (int j = 1; j <= m; j++)
            {
                scanf("%lld", &val[i][j]);
                val[i][j] = -val[i][j];
                val[i][j] += val[i][j - 1];
            }
            st[i].st(i);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &sumq[i]);
            sumq[i] += sumq[i - 1];
        }
        for (int j = 0; j <= m; j++)
        {
            sum = 0;
            for (int i = 1; i <= n; i++)
            {
                sum += st[i].query_max(j, m);
            }
            sum += sumq[j];
            for (int i = 1; i <= n; i++)
            {
                ans = max(sum - st[i].query_max(j, m) + val[i][j], ans);
            }
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}