#include <bits/stdc++.h>

using namespace std;

void pre_EKMP(char x[], int m, int next[])
{
    next[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1])
        j++;
    next[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = next[k] + k - 1;
        int L = next[i - k];
        if (i + L < p + 1)
            next[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j])
                j++;
            next[i] = j;
            k = i;
        }
    }
}

void EKMP(char x[], int m, char y[], int n, int next[], int extend[])
{
    pre_EKMP(x, m, next);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])
        j++;
    extend[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = extend[k] + k - 1;
        int L = next[i - k];
        if (i + L < p + 1)
            extend[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])
                j++;
            extend[i] = j;
            k = i;
        }
    }
}

const int N = 1e6 + 7;
char s[N];
int nxt[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(nxt, 0, sizeof(nxt));
        scanf("%s", s);
        long long sum = 0;
        int len = strlen(s);
        pre_EKMP(s, len, nxt);
        for (int i = 1; i < len; i++)
        {
            if (nxt[i] == 0)
                sum++;
            else
            {
                if (len - i == nxt[i])
                    sum += nxt[i];
                else
                    sum += nxt[i] + 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}