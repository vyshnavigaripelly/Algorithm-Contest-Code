#include <iostream>
#include <numeric>
#include <string>
using namespace std;

int cnt[10], now[10];
long long ans = 0;

long long Fact(int n)
{
    long long s = 1;
    for (int i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

long long nCr(int n, int r)
{
    return Fact(n) / Fact(r) / Fact(n - r);
}

void dfs(int step)
{
    if (step == 10)
    {
        int len = accumulate(now, now + 10, 0), rest = len;
        long long tmp = 1;
        for (int i = 0; i < 10; i++)
        {
            if (now[i] != 0)
            {
                if (i == 0)
                {
                    tmp *= nCr(rest - 1, now[i]);
                    rest -= now[i];
                }
                else
                {
                    tmp *= nCr(rest, now[i]);
                    rest -= now[i];
                }
            }
        }
        ans += tmp;
        return;
    }
    for (int i = 1; i <= cnt[step]; i++)
    {
        now[step] = i;
        dfs(step + 1);
    }
    if (now[step] == 0)
    {
        dfs(step + 1);
    }
}

int main()
{
    string n;
    cin >> n;
    for (char c : n)
    {
        cnt[c - '0']++;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}