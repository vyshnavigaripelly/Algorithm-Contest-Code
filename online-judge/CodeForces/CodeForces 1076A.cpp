#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] > s[i + 1])
        {
            s.erase(s.begin() + i);
            break;
        }
    }
    cout << min(s, t) << endl;
    return 0;
}