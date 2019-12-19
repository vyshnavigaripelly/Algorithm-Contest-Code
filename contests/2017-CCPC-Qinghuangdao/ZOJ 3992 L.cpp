#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s;
        cin >> n >> m;
        cin >> s;
        int l = 0, r = 0;
        for (int i = 1; i < m; i++)
        {
            if (s[i] == 'R')
            {
                l++;
            }
        }
        for (int i = m - 1; i < n - 1; i++)
        {
            if (s[i] == 'L')
            {
                r++;
            }
        }
        cout << min(l, r) << endl;
    }
    return 0;
}