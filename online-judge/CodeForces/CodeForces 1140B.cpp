#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << min(s.find_first_not_of("<"), s.length() - s.find_last_not_of(">") - 1) << endl;
    }
    return 0;
}