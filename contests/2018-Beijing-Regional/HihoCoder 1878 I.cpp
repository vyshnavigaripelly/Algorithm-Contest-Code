#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char str[1000007];
        scanf("%s", str);
        int len = strlen(str);
        if (len == 1)
        {
            printf("%c\n", str[0] - 1);
            continue;
        }
        if (len == 2 && str[0] == '1' && str[1] == '0')
        {
            printf("9\n");
            continue;
        }
        if (str[0] == '1')
        {
            if (str[1] == '0')
            {
                printf("9");
                for (int i = 2; i < len; i++)
                    printf("%c", str[i]);
                for (int i = len - 2; i >= 2; i--)
                    printf("%c", str[i]);
                printf("9");
            }
            else
            {
                for (int i = 1; i < len; i++)
                    printf("%c", str[i]);
                for (int i = len - 1; i >= 1; i--)
                    printf("%c", str[i]);
            }
        }
        else
        {
            str[0] -= 1;
            printf("%c", str[0]);
            for (int i = 1; i < len; i++)
                printf("%c", str[i]);
            for (int i = len - 2; i >= 1; i--)
                printf("%c", str[i]);
            printf("%c", str[0]);
        }
        puts("");
    }
    return 0;
}