#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        while (n--)
        {
            // char/bool 1
            // int/float 4
            // long long/double 8
            // __int128/long double 16
            char s[100], ss[100];
            int mul = 0, flag = 0;
            scanf("%s %s", s, ss);
            if (!strcmp(s, "long"))
            {
                if (!strcmp(ss, "long"))
                {
                    mul = 8;
                }
                else if (!strcmp(ss, "double"))
                {
                    mul = 16;
                }
                scanf("%s", ss);
                flag = 1;
            }
            int len = strlen(ss), cnt = 1;
            if (ss[len - 2] == ']')
            {
                int pos = len - 3, k = 1;
                cnt = 0;
                while (isdigit(ss[pos]))
                {
                    cnt = cnt + (ss[pos] - '0') * k;
                    pos--;
                    k *= 10;
                }
            }
            if (!strcmp(s, "bool") || !strcmp(s, "char"))
            {
                mul = 1;
            }
            else if (!strcmp(s, "int") || !strcmp(s, "float"))
            {
                mul = 4;
            }
            else if (!strcmp(s, "__int128"))
            {
                mul = 16;
            }
            else if (!flag && !strcmp(s, "double"))
            {
                mul = 8;
            }
            ans += mul * cnt;
        }
        printf("Case #%d: %lld\n", cas, (ans + 1023) / 1024);
    }
    return 0;
}