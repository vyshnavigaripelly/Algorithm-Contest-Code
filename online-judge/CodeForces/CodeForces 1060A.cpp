#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '8')
        {
            cnt++;
        }
    }
    cout << min(cnt, n / 11) << endl;
    return 0;
}