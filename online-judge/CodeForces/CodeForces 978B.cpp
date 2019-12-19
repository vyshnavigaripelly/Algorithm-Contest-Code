#include <iostream>
#include <string>
using namespace std;

int main()
{
    int len;
    string s;
    cin >> len >> s;
    int cnt = 0, x = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'x')
        {
            x++;
        }
        else
        {
            x = 0;
        }
        if (x >= 3)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
