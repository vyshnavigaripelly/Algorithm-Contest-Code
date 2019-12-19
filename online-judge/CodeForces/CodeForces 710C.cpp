#include <iostream>

using namespace std;

int map[50][50];

int main()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "2 1 4\n3 5 7\n6 9 8";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        map[n / 2][i] = map[i][n / 2] = 1;
    }
    int cnt = n / 2 * 4 + 1, flag = 1;
    for (int i = 0; i < n / 2 && flag; i++)
    {
        for (int j = 0; j < n / 2 && flag; j++)
        {
            map[i][j] = map[n - 1 - i][n - 1 - j] = map[i][n - 1 - j] = map[n - 1 - i][j] = 1;
            cnt += 4;
            if (cnt == n * n / 2 + 1)
            {
                flag = 0;
            }
        }
    }
    int odd = 1, even = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                map[i][j] = odd;
                odd += 2;
            }
            else
            {
                map[i][j] = even;
                even += 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}