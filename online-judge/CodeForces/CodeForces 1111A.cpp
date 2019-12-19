#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int isvowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    string s, t;
    cin >> s >> t;
    int flag = 1;
    for (int i = 0; i < min(s.length(), t.length()); i++)
    {
        if (isvowel(s[i]) != isvowel(t[i]))
        {
            flag = 0;
        }
    }
    if (s.length() != t.length())
    {
        flag = 0;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}