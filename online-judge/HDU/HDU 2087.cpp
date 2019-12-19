#include <iostream>
#include <cstring>
using namespace std;

int kmpnext[10010];
char a[1007], b[1007];

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
            j = 0;
        }
    }
    return ans;
}

int main()
{
    while (~scanf("%s", a))
    {
        if (a[0] == '#')
        {
            break;
        }
        scanf("%s", b);
        getkmpnext(b, strlen(b), kmpnext);
        printf("%d\n", kmp(b, strlen(b), a, strlen(a), kmpnext));
    }
    return 0;
}
