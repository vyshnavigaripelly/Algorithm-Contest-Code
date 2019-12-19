#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int kmpnext[1000007];
char s[1000007];

void getkmpnext(char pattern[], int lenpat, int next[])
{
    int i = 0, j = next[0] = -1;
    while (i < lenpat)
    {
        while (j != -1 && pattern[i] != pattern[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        getkmpnext(s, len, kmpnext);
        int ans = 0;
        for (int i = kmpnext[len]; i >= 0; i--)
        {
            for (int j = 2 * i; j <= len - i; j++)
            {
                if (kmpnext[j] == i)
                {
                    ans = i;
                    break;
                }
            }
            if (ans != 0)
            {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
