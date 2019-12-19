#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    set<string> se;
    while (cin >> s)
    {
        for (auto &i : s)
        {
            if (!isalpha(i))
            {
                i = ' ';
            }
            else
            {
                i = tolower(i);
            }
        }
        stringstream ss(s);
        string t;
        while (ss >> t)
        {
            se.insert(t);
        }
    }
    for (auto i : se)
    {
        cout << i << endl;
    }
    return 0;
}