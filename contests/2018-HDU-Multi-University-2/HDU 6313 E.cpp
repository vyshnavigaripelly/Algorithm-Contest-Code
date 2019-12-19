#include <iostream>

using namespace std;

const int N = 47;

int map[N * N][N * N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int offset = i * j % N;
            for (int k = 0; k < N; k++)
            {
                map[i * N + k][j * N + (offset + k) % N] = 1;
            }
        }
    }
    int m = 2000, cnt = 0;
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                cnt++;
            }
            printf("%d", map[i][j]);
        }
        puts("");
    }
    return 0;
}