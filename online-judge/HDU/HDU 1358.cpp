#include <iostream>
#include <string>
using namespace std;

int kmpnext[1000007];
char str[1000007];

void getkmpnext(char pattern[], int lenpat, int next[])
{
    int i = 0, j = next[0] = -1;
    while (i < lenpat)
    {
        while (j != -1 && pattern[i] != pattern[j])
            j = next[j];
        next[++i] = ++j;
        if (i % (i - next[i]) == 0 && next[i] != 0)
        {
            printf("%d %d\n", i, i / (i - next[i]));
        }
    }
}

int main()
{
    int len, cas = 1;
    while (~scanf("%d", &len) && len)
    {
        scanf("%s", str);
        printf("Test case #%d\n", cas);
        getkmpnext(str, len, kmpnext);
        puts("");
        cas++;
    }
    return 0;
}
