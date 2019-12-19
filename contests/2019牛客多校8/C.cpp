#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;

int m;
int mp[1100][1100] = {{0, 0, 0, 0}, {0, 1, 1, 1, 1}, {0, 1, 1, -1, -1}, {0, 1, -1, 1, -1}, {0, 1, -1, -1, 1}};
int mp4[1100][1100] = {{0, 0, 0, 0}, {0, 1, 1, 1, 1}, {0, 1, 1, -1, -1}, {0, 1, -1, 1, -1}, {0, 1, -1, -1, 1}};

void solve(int M)
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            mp[i][j] = mp4[i][j];
            mp[i][j + M] = mp4[i][j];
            mp[i + M][j] = mp4[i][j];
            mp[i + M][j + M] = -mp4[i][j];
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
    cin >> m;
    if (m == 2)
    {
        cout << "1 1" << endl
             << "1 -1" << endl;
    }
    else
    {
        int tar = log(m) / log(2);
        for (int i = 3; i <= tar; i++)
        {
            solve(pow(2, i - 1));
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%d ", mp[i][j]);
            }
            puts("");
        }
    }
    return 0;
}