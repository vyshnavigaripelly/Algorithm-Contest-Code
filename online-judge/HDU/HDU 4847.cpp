#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int kmpnext[5];
char str[1000007], pat[] = "doge";

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

int kmp(char str[], int lenstr, char pattern[], int lenpat, int next[])
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
    int ans = 0;
    getkmpnext(pat, 4, kmpnext);
    while (gets(str))
    {
        int len = strlen(str);
        transform(str, str + len, str, ::tolower);
        ans += kmp(str, len, pat, 4, kmpnext);
    }
    printf("%d\n", ans);
    return 0;
}
