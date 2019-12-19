#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int p = 1, len = s.length();
        for (p = 1; p < len; p++)
        {
            if (len % p != 0)
            {
                continue;
            }
            string sub = string(s, 0, p);
            int cnt = 0;
            for (int i = 0; i < len / p; i++)
            {
                if (string(s, i * p, p) != sub)
                {
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            if (cnt == len / p)
            {
                break;
            }
        }
        cout << p << endl;
        if (t != 0)
        {
            cout << endl;
        }
    }
    return 0;
}
