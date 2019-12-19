#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string ss = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t;
    cin >> t;
    while (t--)
    {
        int sqr[6][6] = {0}, cnt[6][6] = {0};
        string s;
        cin >> s;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (isdigit(s[i]))
            {
                sqr[0][s[i] - '0']++;
            }
            else
            {
                sqr[0][10 + s[i] - 'A']++;
            }
        }
        int max = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int k = 0; k < 6; k++)
                {
                    cnt[i][j] += sqr[i][k] + sqr[k][j];
                }
                if (cnt[i][j] > max)
                {
                    max = cnt[i][j];
                }
            }
        }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (cnt[i][j] == max)
                {
                    cout << ss[6 * i + j];
                }
            }
        }
        cout << endl;
    }
    return 0;
}