#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;

int nxt[maxn][26];
char s[maxn], pat[maxn];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s %s", s + 1, pat + 1);
    for (int i = 0; i < 26; i++)
    {
        nxt[n][i] = -1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    int mx = -1;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = pat[i] - 'a' + 1; j < 26; j++)
        {
            if (nxt[cnt][j] != -1)
            {
                mx = max(mx, n - nxt[cnt][j] + i);
            }
        }
        cnt = nxt[cnt][pat[i] - 'a'];
        if (cnt == -1)
            break;
    }
    if (cnt != n && cnt != -1)
    {
        mx = max(mx, n - cnt + m);
    }
    printf("%d\n", mx);
    return 0;
}