#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    }
    return 0;
}
