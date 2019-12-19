#include <iostream>
using namespace std;

int main()
{
    int m, n;
    long long a[21][21] = {0};
    for (int i = 1; i < 21; i++)
    {
        for (int j = i; j < 21; j++)
        {
            if (i == 1)
            {
                a[i][j] = j;
            }
            else
            {
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
    }
    while (cin >> m >> n)
    {
        cout << a[n][m] << endl;
    }
    return 0;
}
