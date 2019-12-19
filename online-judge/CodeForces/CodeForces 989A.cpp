#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.find("ABC") == string::npos && s.find("ACB") == string::npos && s.find("BAC") == string::npos &&
        s.find("BCA") == string::npos && s.find("CAB") == string::npos && s.find("CBA") == string::npos)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}