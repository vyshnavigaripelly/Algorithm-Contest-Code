#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 7;
const int mod = 1e9 + 7;

int tmp[MAXN], nxt[MAXN];

void kmp_pre(char x[], int m, int next[])
{
    int i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int KMP_Count(char x[], int m, char y[], int n)
{
    int i, j;
    int ans = 0;
    kmp_pre(x, m, nxt);

    i = j = 0;
    while (i < n)
    {
        while (-1 != j && y[i] != x[j])
            j = nxt[j];
        i++, j++;
        if (j >= m)
        {
            tmp[i] = 1;
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}

long long f[MAXN];
char s1[MAXN], s2[MAXN];

int main()
{
    int T, cas = 0;
    cin >> T;
    while (T--)
    {
        scanf("%s", s1);
        scanf("%s", s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        memset(f, 0, sizeof f);
        memset(tmp, 0, sizeof tmp);
        int sum = KMP_Count(s2, len2, s1, len1);
        for (int i = len2; i <= len1; i++)
        {
            if (tmp[i])
            {
                f[i] = f[i - 1] + f[i - len2] + 1;
                f[i] %= mod;
            }
            else
                f[i] = f[i - 1];
        }
        printf("Case #%d: %lld\n", ++cas, f[len1] + 1);
    }
    return 0;
}