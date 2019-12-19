#include <iostream>

using namespace std;

char str[20][20];

int main()
{
    int n, m, a, b;
    while (~scanf("%d %d %d %d", &n, &m, &a, &b))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
        }
        for (int i = 0; i < n * a; i++)
        {
            for (int j = 0; j < m * b; j++)
            {
                printf("%c", str[i / a][j / b]);
            }
            puts("");
        }
    }
    return 0;
}