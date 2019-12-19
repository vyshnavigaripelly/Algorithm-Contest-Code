#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> ma, mb;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        ma.clear();
        mb.clear();
        int lena = a.length(), lenb = b.length();
        for (auto i : a)
            ma[i]++;
        for (auto i : b)
            mb[i]++;
        if (a == b)
            cout << "Equal" << endl;
        else if (a[0] == b[0] && a[lena - 1] == b[lenb - 1] && ma == mb)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}