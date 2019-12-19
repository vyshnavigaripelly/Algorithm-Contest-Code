#include <iostream>
#include <cctype>
using namespace std;

void check(string &s)
{
    for (char &k : s)
    {
        k = tolower(k);
        if (k == 'o')
        {
            k = '0';
        }
        if (k == '1' || k == 'i')
        {
            k = 'l';
        }
    }
}

int main()
{
    string s;
    cin >> s;
    check(s);
    int n;
    cin >> n;
    int flag = 1;
    while (n--)
    {
        string t;
        cin >> t;
        check(t);
        if (s == t)
        {
            flag = 0;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
