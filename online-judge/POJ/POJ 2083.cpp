#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 3 * 3 * 3 * 3 * 3 * 3 + 7;

char mp[N][N];

void solve(int n, int x, int y)
{
    if (n == 1)
    {
        mp[x][y] = 'X';
        return;
    }
    int size = pow(3, n - 2);
    solve(n - 1, x, y);
    solve(n - 1, x - size, y - size);
    solve(n - 1, x - size, y + size);
    solve(n - 1, x + size, y - size);
    solve(n - 1, x + size, y + size);
}

int main()
{
    int n;
    while (cin >> n && n != -1)
    {
        memset(mp, ' ', sizeof(mp));
        int size = pow(3, n - 1);
        solve(n, size / 2, size / 2);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << mp[i][j];
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}