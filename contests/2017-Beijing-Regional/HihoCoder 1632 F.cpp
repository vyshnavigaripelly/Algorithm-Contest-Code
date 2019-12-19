#include <iostream>
#include <cstring>

using namespace std;

char mp[107][107], str[10007], ans[107][107];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
        }
        int len = 0;
        for (int i = 0; i <= 2 * (n - 1); i++)
        {
            if (i < n)
            {
                for (int j = 0; j <= i; j++)
                {
                    str[len++] = (i % 2 == 0) ? mp[i - j][j] : mp[j][i - j];
                }
            }
            else
            {
                for (int j = 0; j <= 2 * (n - 1) - i; j++)
                {

                    str[len++] = (i % 2 == 0)
                                     ? mp[n - 1 - j][n - 1 - (2 * (n - 1) - i) + j]
                                     : mp[n - 1 - (2 * (n - 1) - i) + j][n - 1 - j];
                }
            }
        }
        memset(ans, 0, sizeof(ans));
        int r = 0, c = 0;
        int cur = 0;
        while (cur < len)
        {
            while (c < n - 1 && ans[r][c + 1] == 0)
            {
                ans[r][c++] = str[cur++];
            }
            while (r < n - 1 && ans[r + 1][c] == 0)
            {
                ans[r++][c] = str[cur++];
            }
            while (c > 0 && ans[r][c - 1] == 0)
            {
                ans[r][c--] = str[cur++];
            }
            while (r > 0 && ans[r - 1][c] == 0)
            {
                ans[r--][c] = str[cur++];
            }
            if (cur == len - 1)
            {
                ans[r][c] = str[cur++];
            }
        }
        for (int i = 0; i < n; i++)
        {
            puts(ans[i]);
        }
    }
    return 0;
}