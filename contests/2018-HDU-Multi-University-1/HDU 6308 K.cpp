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
        int h, m, flag = -1;
        char tz[10];
        scanf("%d%d%s", &h, &m, tz);
        int times = h * 60 + m - 480;
        if (tz[3] == '+')
            flag = 1;
        if (strlen(tz) == 6 || strlen(tz) == 8)
            times += ((tz[4] - '0') * 10 + tz[5] - '0') * flag * 60;
        else
            times += (tz[4] - '0') * flag * 60;
        if (strlen(tz) == 7)
            times += (tz[6] - '0') * flag * 6;
        else if (strlen(tz) == 8)
            times += (tz[7] - '0') * flag * 6;
        if (times < 0)
            times += 1440;
        times %= 1440;
        printf("%02d:%02d\n", times / 60, times % 60);
    }

    return 0;
}