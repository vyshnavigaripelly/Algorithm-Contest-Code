#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;

int m;
int mp[1100][1100] = {{0}, {0, 1, 1}, {0, -1, 1}};
int mp4[1100][1100] = {{0}, {0, 1, 1}, {0, -1, 1}};

void solve(int M)
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            mp[i][j] = mp4[i][j];
            mp[i][j + M] = mp4[i][j];
            mp[i + M][j] = -mp4[i][j];
            mp[i + M][j + M] = mp4[i][j];
        }
    }
    for (int i = 1; i <= M * 2; i++)
    {
        for (int j = 1; j <= M * 2; j++)
        {
            mp4[i][j] = mp[i][j];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &m);
        if (m == 1)
        {
            printf("CC\nPC\n");
        }
        else
        {
            int tar = pow(2, m);
            for (int i = 2; i <= m; i++)
            {
                solve(pow(2, i - 1));
            }
            for (int i = 1; i <= tar; i++)
            {
                for (int j = 1; j <= tar; j++)
                {
                    if (mp[i][j] == 1)
                    {
                        printf("C");
                    }
                    else
                    {
                        printf("P");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}