#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string s[150];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, [](const string &a, const string &b) {
        return a.size() < b.size();
    });
    int flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i].find(s[i - 1]) == string::npos)
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}