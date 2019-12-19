#include <iostream>
#include <map>
#include <set>

using namespace std;

set<pair<string, string>> se;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        se.insert({a, b});
    }
    cout << se.size() << endl;
    return 0;
}