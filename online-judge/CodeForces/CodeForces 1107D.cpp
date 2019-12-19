#include <iostream>
#include <cstdio>

using namespace std;

int map[5500][5500], sum[5500][5500];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j += 4)
        {
            char c = getchar();
            int tmp = 0;
            if (isdigit(c))
            {
                tmp = c - '0';
            }
            else
            {
                tmp = c - 'A' + 10;
            }
            for (int k = 3; k >= 0; k--)
            {
                map[i][j + k] = (tmp & 1);
                tmp >>= 1;
            }
        }
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + -sum[i - 1][j - 1] + map[i][j];
        }
    }
    for (int i = n; i > 0; i--)
    {
        if (n % i != 0)
        {
            continue;
        }
        int num = n / i, flag = 1;
        for (int j = 0; j < num && flag; j++)
        {
            for (int k = 0; k < num && flag; k++)
            {
                int x1 = j * i + 1, y1 = k * i + 1;
                int x2 = (j + 1) * i, y2 = (k + 1) * i;
                int tmpsum = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
                if (tmpsum != 0 && tmpsum != i * i)
                {
                    flag = 0;
                }
            }
        }
        if (flag)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}