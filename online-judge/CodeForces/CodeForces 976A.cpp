#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    if (s == "0")
    {
        cout << "0" << endl;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                cnt++;
            }
        }
        cout << 1 << string(cnt, '0');
    }
    return 0;
}
