#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int ans[26];
int flag[26];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        cin >> n >> str;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < str.length(); i++)
        {
            ans[str[i] - 'A']++;
        }
        for (int i = 1; i < n; i++)
        {
            cin >> str;
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < str.length(); j++)
            {
                flag[str[j] - 'A']++;
            }
            for (int j = 0; j < 26; j++)
            {
                ans[j] = min(ans[j], flag[j]);
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < ans[i]; j++)
            {
                cout << char(i + 'A');
            }
        }
        cout << endl;
    }
    return 0;
}