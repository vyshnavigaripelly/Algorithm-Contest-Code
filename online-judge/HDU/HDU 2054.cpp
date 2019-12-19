#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[2];
    while (cin >> str[0] >> str[1])
    {
        for (auto &s : str)
        {
            int sgn = (s[0] == '+') ? 1 : ((s[0] == '-') ? -1 : 0);
            s = (sgn != 0) ? s.substr(1) : s;
            s = "0" + s + ((s.find(".") == string::npos) ? ".0" : "0");
            s.erase(s.find_last_not_of("0") + 1);
            s.erase(0, s.find_first_not_of("0"));
            s = ((sgn != -1 || s == ".") ? "+" : "-") + s;
        }
        cout << (str[0] == str[1] ? "YES" : "NO") << endl;
    }
    return 0;
}