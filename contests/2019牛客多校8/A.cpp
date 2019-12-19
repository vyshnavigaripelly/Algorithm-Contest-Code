#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 10;

int a[N][N], n, m, aa;
int sta[N], tot, l[N], r[N];
int arr[N * N], cnt, num;
long long ans[N * N];
char s[N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[j] == '1')
            {
                a[i][j] = 1;
                a[i][j] += a[i][j - 1];
            }
        }
    }
    int st, ed;
    for (int j = 1; j <= m; j++)
    {
        tot = st = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == 0)
                tot = 0, st = i;
            else
            {
                while (tot && a[sta[tot]][j] >= a[i][j])
                    tot--;
                if (tot == 0)
                    l[i] = st;
                else
                    l[i] = sta[tot];
                sta[++tot] = i;
            }
        }
        tot = 0, ed = n + 1;
        for (int i = n; i >= 1; i--)
        {
            if (a[i][j] == 0)
                tot = 0, ed = i;
            else
            {
                while (tot && a[sta[tot]][j] >= a[i][j])
                    tot--;
                if (tot == 0)
                    r[i] = ed;
                else
                    r[i] = sta[tot];
                sta[++tot] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j])
            {
                ans[num++] = (j - a[i][j] + 1) * 3001LL * 3001LL + l[i] * 3001LL + r[i] - 1;
            }
        }
    }
    sort(ans, ans + num);
    cnt = min(1, num);
    for (int i = 0; i < num - 1; i++)
    {
        if (ans[i] != ans[i + 1])
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}