#include <iostream>

using namespace std;

int cnt[26][3];

string arr[6] = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 99999999, pos = -1;
    for (int i = 0; i < 6; i++)
    {
        int cnt = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != arr[i][j % 3])
            {
                cnt++;
            }
        }
        if (cnt < ans)
        {
            ans = min(ans, cnt);
            pos = i;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[pos][i % 3];
    }
    return 0;
}