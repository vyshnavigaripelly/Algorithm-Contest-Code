#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 5e5 + 7;
char s[N], t[N], ans[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &s[i]);
        t[n - 1 - i] = s[i];
    }
    int cnt = 0, pos1 = 0, pos2 = 0;
    while (cnt <= n - 1)
    {
        if (strcmp(s + pos1, t + pos2) < 0)
        {
            ans[cnt] = s[pos1];
            t[n - 1 - pos1] = '\0';
            pos1++;
        }
        else
        {
            ans[cnt] = t[pos2];
            s[n - 1 - pos2] = '\0';
            pos2++;
        }
        cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", ans[i]);
        if (i % 80 == 79)
            puts("");
    }
    return 0;
}