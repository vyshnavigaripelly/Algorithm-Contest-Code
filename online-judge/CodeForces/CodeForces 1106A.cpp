#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[507];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int cnt = 0;
    char c = 'X';
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (s[i][j] == c && s[i - 1][j - 1] == c && s[i - 1][j + 1] == c && s[i + 1][j - 1] == c && s[i + 1][j + 1] == c)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}