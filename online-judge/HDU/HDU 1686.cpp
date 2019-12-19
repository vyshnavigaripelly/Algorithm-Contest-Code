#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int kmpnext[10010];
char a[10010], b[1000020];

void getkmpnext(char pattern[], int lenpat, int next[])
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

int kmp(char pattern[], int lenpat, char str[], int lenstr, int next[])
{
    int i = 0, j = 0, ans = 0;
    while (i < lenstr)
    {
        while (j != -1 && pattern[j] != str[i])
            j = next[j];
        i++, j++;
        if (j >= lenpat)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s %s", a, b);
        memset(kmpnext, 0, sizeof(kmpnext));
        getkmpnext(a, strlen(a), kmpnext);
        printf("%d\n", kmp(a, strlen(a), b, strlen(b), kmpnext));
    }
    return 0;
}
