#include <iostream>
#include <string>
using namespace std;

int kmpnext[10010];
int a[1000007], b[10007];

void getkmpnext(int pattern[], int lenpat, int next[])
{
    int i = 0, j = next[0] = -1;
    while (i < lenpat)
    {
        while (j != -1 && pattern[i] != pattern[j])
            j = next[j];
        if (pattern[++i] == pattern[++j])
            next[i] = next[j];
        else
            next[i] = j;
    }
}

int kmp(int pattern[], int lenpat, int str[], int lenstr, int next[])
{
    int i = 0, j = 0, ans = 0;
    while (i < lenstr)
    {
        while (j != -1 && pattern[j] != str[i])
            j = next[j];
        i++, j++;
        if (j >= lenpat)
        {
            return i - j + 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        getkmpnext(b, m, kmpnext);
        cout << kmp(b, m, a, n, kmpnext) << endl;
    }
    return 0;
}
