#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string name, s;
    map<string, int> ans;
    while (cin >> name)
    {
        if (name[0] == '-')
        {
            for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
            {
                cout << it->first << ' ' << it->second << endl;
            }
            cout << string(10, '-') << endl;
            ans.clear();
        }
        else
        {
            getline(cin, s);
            ans[name] += s.length() - 1; // extra space after ':'
        }
    }
    return 0;
}
