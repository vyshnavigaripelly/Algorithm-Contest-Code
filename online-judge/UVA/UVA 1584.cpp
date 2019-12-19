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
        int len = s.length();
        string min = s;
        s += s;
        for (int i = 0; i < len; i++)
        {
            string tmp = string(s, i, len);
            if (tmp < min)
            {
                min = tmp;
            }
        }
        cout << min << endl;
    }
    return 0;
}
