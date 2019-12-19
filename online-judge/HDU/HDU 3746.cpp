#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int kmpnext[100007];
char str[100007];

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
        scanf("%s", str);
        int len = strlen(str);
        getkmpnext(str, len, kmpnext);
        int loop = len - kmpnext[len];
        if (len % loop == 0 && len != loop)
        {
            puts("0");
        }
        else
        {
            printf("%d\n", loop - kmpnext[len] % loop);
        }
    }
    return 0;
}
