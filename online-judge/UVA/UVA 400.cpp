#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

string s[1007];

int main()
{
    int n;
    while (cin >> n)
    {
        int maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            maxlen = max(maxlen, (int)s[i].length());
        }
        cout << string(60, '-') << endl;
        sort(s, s + n);
        int col = (60 - maxlen) / (maxlen + 2) + 1;
        int row = (n + col - 1) / col;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int pos = j * row + i;
                cout << left << setw(maxlen + 2) << (pos < n ? s[pos] : "");
            }
            cout << endl;
        }
    }
    return 0;
}