#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[2007][2007];

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        memset(dp, 0, sizeof(dp));
        int lena = a.length(), lenb = b.length();
        for (int i = 0; i <= lena; i++)
        {
            for (int j = 0; j <= lenb; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[lena][lenb] << endl;
    }
    return 0;
}