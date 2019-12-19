#include <iostream>
#include <string>

using namespace std;

string s[107];

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int r = 0; r < k; r++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int c = 0; c < k; c++)
                    {
                        cout << s[i][j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}