#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int flag = 1;
        for (int i = 0; i <= s.size() / 2; i++)
        {
            if (!(abs(s[i] - s[s.size() - 1 - i]) == 2 || abs(s[i] - s[s.size() - 1 - i]) == 0))
            {
                flag = 0;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}