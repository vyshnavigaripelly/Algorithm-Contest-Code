#include <iostream>

using namespace std;

int a[507][507], b[507][507];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cnt++;
            }
        }
        if (cnt % 2 == 1)
        {
            flag = 0;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] != b[i][j])
            {
                cnt++;
            }
        }
        if (cnt % 2 == 1)
        {
            flag = 0;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}