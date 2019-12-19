#include <iostream>
#include <cstring>

using namespace std;

char map[100][100];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(map, '.', sizeof(map));
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        for (int i = 2 * b; i <= 2 * b + 2 * c; i++)
        {
            for (int j = 0; j <= 2 * a; j++)
            {
                if ((i - 2 * b) % 2 == 0)
                {
                    if (j % 2 == 0)
                        map[i][j] = '+';
                    else
                        map[i][j] = '-';
                }
                else
                {
                    if (j % 2 == 0)
                        map[i][j] = '|';
                }
            }
        }
        for (int i = 2 * b - 1; i >= 0; i--)
        {
            for (int j = 2 * b - i; j <= 2 * b + 2 * a - i; j++)
            {
                if (i % 2 == 0)
                {
                    if ((j - (i - 2 * b)) % 2 == 0)
                        map[i][j] = '+';
                    else
                        map[i][j] = '-';
                }
                else
                {
                    if ((j - (i - 2 * b)) % 2 == 0)
                        map[i][j] = '/';
                }
            }
        }
        for (int j = 2 * a + 2 * b; j >= 2 * a; j--)
        {
            for (int i = 2 * a + 2 * b - j; i <= 2 * a + 2 * b - j + 2 * c; i++)
            {
                if (i % 2 == 0)
                {
                    if ((j - (i - 2 * b)) % 2 == 0)
                        map[i][j] = '+';
                }
                else
                {
                    if ((j - (i - 2 * b)) % 2 == 0)
                        map[i][j] = '/';
                    else
                        map[i][j] = '|';
                }
            }
        }
        for (int i = 0; i <= 2 * b + 2 * c; i++)
        {
            for (int j = 0; j <= 2 * a + 2 * b; j++)
            {
                printf("%c", map[i][j]);
            }
            puts("");
        }
    }
    return 0;
}