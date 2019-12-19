#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string map[15][15];

int main()
{
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
            }
        }
        cout << "Case " << cas << ":\n";
        while (q--)
        {
            string s;
            cin >> s;
            for (int i = 0; i < s.length(); i += 2)
            {
                cout << map[s[i + 1] - '1' + 1][s[i] - 'A' + 1];
            }
            cout << endl;
        }
    }
    return 0;
}