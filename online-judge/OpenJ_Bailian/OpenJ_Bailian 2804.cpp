#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    map<string, string> dict;
    string a, b, s;
    while (getline(cin, s) && s.length() != 0)
    {
        stringstream ss(s);
        ss >> a >> b;
        dict[b] = a;
    }
    while (cin >> s)
    {
        map<string, string>::iterator it = dict.find(s);
        if (it != dict.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
    return 0;
}
