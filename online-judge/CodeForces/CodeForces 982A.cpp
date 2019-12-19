#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> n >> s;
    s = "0" + s + "0";
    if (s.find("000") == string::npos && s.find("11") == string::npos)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
