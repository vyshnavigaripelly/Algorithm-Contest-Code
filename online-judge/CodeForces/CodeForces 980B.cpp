#include <iostream>
#include <cstring>
using namespace std;

char map[4][150];

int main()
{
    memset(map, '.', sizeof(map));
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        for (int i = 1; i <= k / 2; i++)
        {
            map[1][i] = '#';
            map[2][i] = '#';
        }
    }
    else
    {
        int cnt = k;
        map[1][n / 2] = '#';
        cnt--;
        for (int i = 1; cnt && i <= n / 2 - 1; i++)
        {
            map[1][n / 2 - i] = '#';
            map[1][n / 2 + i] = '#';
            cnt -= 2;
        }
        if (cnt > 0)
        {
            for (int i = 1; i <= k / 2 - 1 && cnt; i++)
            {
                map[2][i] = '#';
                map[2][n - i - 1] = '#';
                cnt -= 2;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}
