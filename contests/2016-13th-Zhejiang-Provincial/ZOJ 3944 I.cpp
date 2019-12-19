#include <iostream>
#include <cstdio>

using namespace std;

char s[207][207];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 3; i < n + 3; i++)
        {
            scanf("%s", s[i] + 3);
        }
        int ans = 0;
        for (int i = 1; i < n + 3; i++)
        {
            for (int j = 1; j < m + 3; j++)
            {
                if (s[i][j + 1] == 'O' || s[i + 1][j] == '/' || s[i + 1][j + 1] == '|' ||
                    s[i + 1][j + 2] == '\\' || s[i + 2][j] == '(' || s[i + 2][j + 2] == ')')
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}