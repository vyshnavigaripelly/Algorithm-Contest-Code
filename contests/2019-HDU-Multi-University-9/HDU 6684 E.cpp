#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'y')
            {
                continue;
            }
            else
            {
                if (s[i] == 'z')
                    s[i] = 'b';
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}