#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        set<string> se;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s)
        {
            se.insert(s);
        }
        cout << se.size() << endl;
    }
    return 0;
}