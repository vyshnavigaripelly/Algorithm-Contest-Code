#include <iostream>
#include <list>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        list<char> txt;
        list<char>::iterator it = txt.begin();
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '[')
            {
                it = txt.begin();
            }
            else if (s[i] == ']')
            {
                it = txt.end();
            }
            else
            {
                it = txt.insert(it, s[i]);
                it++;
            }
        }
        for (it = txt.begin(); it != txt.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
