#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int arr[30];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        set<char> se(s.begin(), s.end());
        if (se.size() == s.length() && *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()) + 1 == s.length())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}