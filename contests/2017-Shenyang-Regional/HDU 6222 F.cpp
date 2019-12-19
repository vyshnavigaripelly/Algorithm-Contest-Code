#include <iostream>
#include <cstdio>
using namespace std;

__int128 f[100] = {4, 14, 52};

void scan(__int128 &x)
{
    x = 0;
    int f = 1;
    char ch;
    if ((ch = getchar()) == '-')
        f = -f;
    else
        x = x * 10 + ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9')
        x = x * 10 + ch - '0';
    x *= f;
}

void print(__int128 x)
{
    if (x < 0)
    {
        x = -x;
        putchar('-');
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    for (int i = 2; i < 70; i++)
    {
        f[i] = f[i - 1] * 4 - f[i - 2];
    }
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        __int128 n;
        scan(n);
        for (int i = 0; i < 70; i++)
        {
            if (f[i] > n - 1)
            {
                print(f[i]);
                puts("");
                break;
            }
        }
    }
    return 0;
}