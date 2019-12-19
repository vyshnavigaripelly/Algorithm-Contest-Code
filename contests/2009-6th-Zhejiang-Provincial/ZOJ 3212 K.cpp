#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int area[20][20];
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                area[i][j] = 1;
            }
        }
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (k == 0)
                {
                    break;
                }
                area[i][j] = 0;
                area[i - 1][j] = 0;
                area[i + 1][j] = 0;
                area[i][j - 1] = 0;
                area[i][j + 1] = 0;
                k--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d", area[i][j]);
                if (j != m - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
