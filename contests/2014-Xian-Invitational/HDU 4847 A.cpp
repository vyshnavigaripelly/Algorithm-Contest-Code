#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[10000007];

int main()
{
    int ans = 0;
    while (gets(s))
    {
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if ((s[i] == 'd' || s[i] == 'D') && (s[i + 1] == 'o' || s[i + 1] == 'O') &&
                (s[i + 2] == 'g' || s[i + 2] == 'G') && (s[i + 3] == 'e' || s[i + 3] == 'E'))
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}