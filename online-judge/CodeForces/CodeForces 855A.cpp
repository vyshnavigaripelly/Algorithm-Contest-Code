#include <iostream>
#include <set>

using namespace std;

set<string> se;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << (se.count(s) ? "YES" : "NO") << endl;
        se.insert(s);
    }
    return 0;
}