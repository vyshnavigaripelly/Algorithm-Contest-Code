#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str[40];
long long len[100] = {0, 6, 7}, flag;

void dfs(int n, long long k, long long l)
{
    if (n < 10)
    {
        int cnt = 0;
        for (int i = k - 1; i < str[n].size() && cnt < l; cnt++, i++)
        {
            printf("%c", str[n][i]);
        }
        return;
    }
    if (k <= len[n - 2])
    {
        dfs(n - 2, k, min(l, len[n - 2] - k + 1));
        long long res = l - min(l, (len[n - 2] - k + 1));
        if (res > 0)
        {
            dfs(n - 1, 1, res);
        }
    }
    else
    {
        dfs(n - 1, k - len[n - 2], l);
    }
}

int main()
{
    str[1] = "COFFEE", str[2] = "CHICKEN";
    for (int i = 3; i <= 30; i++)
    {
        str[i] = str[i - 2] + str[i - 1];
    }
    for (int i = 3; i <= 70; i++)
    {
        len[i] = len[i - 1] + len[i - 2];
        if (len[i] > (long long)1e13)
            break;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        flag = 0;
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        if (n >= 59)
        {
            flag = 1;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (len[i] > k)
                {
                    if ((len[i] - 10) >= (k - 1))
                    {
                        flag = 1;
                    }
                }
            }
        }
        dfs(min(59, n), k, 10);
        puts("");
    }
    return 0;
}