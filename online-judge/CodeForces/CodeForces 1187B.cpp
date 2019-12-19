#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> pos[26];
int cur[26];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        pos[s[i] - 'a'].push_back(i);
    }
    int m;
    cin >> m;
    while (m--)
    {
        memset(cur, -1, sizeof(cur));
        string t;
        cin >> t;
        for (int i = 0; i < t.length(); i++)
        {
            cur[t[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cur[i] != -1)
            {
                ans = max(ans, pos[i][cur[i]]);
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}