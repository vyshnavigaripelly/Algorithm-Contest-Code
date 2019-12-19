#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    int ans = 0;
    cin >> str;
    for (int i = 0; !str.empty() && i < (str.size() - 2); i++)
    {
        if (str[i] == str[i + 1] && str[i + 1] == str[i + 2])
        {
            ans++;
            str.erase(str.begin() + i, str.begin() + i + 3);
            i = max(-1, i - 3);
        }
    }
    cout << ans << endl;
    return 0;
}