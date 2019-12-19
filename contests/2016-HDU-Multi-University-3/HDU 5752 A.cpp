#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

char str[107];

int main()
{
    while (~scanf("%s", str))
    {
        int len = strlen(str);
        if (len >= 17)
        {
            puts("TAT");
            continue;
        }
        long long a = 0;
        for (int i = 0; i < len; i++)
        {
            a = 10 * a + str[i] - '0';
        }
        if (a == 1)
        {
            puts("1");
            continue;
        }
        int ans = 0;
        while (a != 1)
        {
            a = floor(sqrt(a));
            ans++;
            if (ans > 5)
            {
                break;
            }
        }
        if (ans > 5)
            puts("TAT");
        else
            printf("%d\n", ans);
    }
    return 0;
}