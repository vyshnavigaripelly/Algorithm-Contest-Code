#include <iostream>
#include <algorithm>

using namespace std;

int a[50][50], b[50][50];

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> b[i][j];
            }
        }
        int ans = 0, tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == b[i][j])
                {
                    tmp++;
                }
            }
        }
        ans = max(tmp, ans);
        tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == b[j][n - i - 1])
                {
                    tmp++;
                }
            }
        }
        ans = max(tmp, ans);
        tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == b[n - i - 1][n - j - 1])
                {
                    tmp++;
                }
            }
        }
        ans = max(tmp, ans);
        tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == b[n - j - 1][i])
                {
                    tmp++;
                }
            }
        }
        ans = max(tmp, ans);
        cout << ans << endl;
    }
    return 0;
}