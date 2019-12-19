#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char s[507];
int n;

int check()
{
    for (int i = 1; i < n; i++)
    {
        if ((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*'))
        {
            return 0;
        }
        if (!isdigit(s[i - 1]) && s[i] == '0' && isdigit(s[i + 1]))
        {
            return 0;
        }
        if (s[1] == '+' || s[1] == '*' || s[n] == '+' || s[n] == '*')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++)
        {
            if (s[i + 1] == '?' && s[i] == '0' && !isdigit(s[i - 1]))
            {
                s[i + 1] = '+';
            }
            else if (s[i] == '?')
            {
                s[i] = '1';
            }
        }
        if (check())
        {
            printf("%s\n", s + 1);
        }
        else
        {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}