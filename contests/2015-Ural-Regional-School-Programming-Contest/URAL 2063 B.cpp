#include <iostream>

using namespace std;

int main()
{
    char str[1000007];
    int t;
    scanf("%d", &t);
    for (int now = 0; now < t; now++)
    {
        scanf("%s", str);
        int cnt = now + 2;
        for (int i = 1; i <= cnt - 1; i++)
        {
            for (int j = i + 1; j <= cnt; j++)
            {
                printf("? %d %d\n", i, j);
            }
        }
        printf("! %d %d\n", cnt / 2, cnt / 2 + 1);
    }
    return 0;
}