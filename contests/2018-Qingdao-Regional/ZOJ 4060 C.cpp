#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char str1[1000007], str2[1000007], ans[1000007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int len;
        scanf("%d %s %s", &len, str1, str2);
        for (int i = 0; i < len; i++)
        {
            ans[i] = (str1[i] == str2[i] ? 0 : 1);
        }
        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (ans[i] != 0)
            {
                cnt++;
                while (ans[i] && i < len)
                {
                    i++;
                }
                i--;
            }
        }
        if (len == 1 && cnt == 1)
        {
            puts("0");
        }
        else if (cnt == 0)
        {
            printf("%d\n", (len + 1) * len / 2);
        }
        else if (cnt == 1)
        {
            printf("%d\n", (len - 1) * 2);
        }
        else if (cnt == 2)
        {
            puts("6");
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}