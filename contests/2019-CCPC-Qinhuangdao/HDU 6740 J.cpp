#include <bits/stdc++.h>

using namespace std;
const int N = 2e7 + 7;

int nxt[N];
char arr[N], brr[N];

void kmp_pre(char x[], int m, int nxt[])
{
    int i, j;
    j = nxt[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
            j = nxt[j];
        nxt[++i] = ++j;
    }
}

int main()
{
    long long a, b, ans;
    while (~scanf("%lld %lld", &a, &b))
    {
        memset(nxt, 0, sizeof nxt);
        scanf("%s", arr);
        int len = strlen(arr);
        int lenth = 0;
        ans = -0x7fffffffffffffff;
        for (int i = len - 1, j = 0; i >= 0; i--, j++)
        {
            if (arr[i] == '.')
            {
                lenth = j;
                break;
            }
            brr[j] = arr[i];
        }
        kmp_pre(brr, lenth, nxt);
        for (int i = 1; i <= lenth; i++)
        {
            long long T = i / (lenth - nxt[i]) * (i - nxt[i]);
            long long tmp = 1ll * a * i - 1ll * b * (i - nxt[i]);
            ans = max(tmp, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}