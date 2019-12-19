#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        string a, b;
        cin >> a >> b;
        int len = a.length(), ans = 1;
        for (int i = 0; i < len; i++)
        {
            int l = max(0, i - m), r = min(len - 1, i + m), flag = 0;
            for (int j = l; j <= r; j++)
            {
                if (a[i] == b[j])
                {
                    b[j] = 'X';
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                ans = 0;
                break;
            }
        }
        cout << (ans ? "yes" : "no") << endl;
    }
    return 0;
}