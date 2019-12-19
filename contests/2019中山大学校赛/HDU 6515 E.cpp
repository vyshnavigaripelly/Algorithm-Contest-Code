#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char bit[3000007], str[300007];

int main()
{
    scanf("%s", str);
    int len = strlen(str), cnt = 0, pos = 0;
    for (int i = 0; i < len; i++)
    {
        int now = 0;
        while (++now <= 8)
        {
            bit[cnt++] = str[i] & 1;
            str[i] >>= 1;
        }
    }
    for (int i = 0; i < 8 * len / 6; i++)
    {
        int now = 0, tmp = 0;
        while (++now <= 6)
        {
            tmp <<= 1;
            tmp |= bit[pos++];
        }
        printf("%d ", tmp);
    }
    return 0;
}