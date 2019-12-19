#include <iostream>
#include <regex>
#include <cctype>

using namespace std;

int main()
{
    string rep = "(";
    for (char i = 'a'; i <= 'z'; i++)
    {
        rep.append(string() + i + "*|" + (char)toupper(i) + "*");
        rep.append(i != 'z' ? "|" : ")");
    }
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        b = regex_replace(b, regex("\\.\\*"), rep);
        cout << (regex_match(a, regex(b)) ? "yes" : "no") << endl;
    }
    return 0;
}