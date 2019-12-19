#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int op, y;
        string x;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y;
            mp[x] += y;
        }
        else if (op == 2)
        {
            mp.erase(x);
        }
        else if (op == 3)
        {
            cout << mp[x] << endl;
        }
    }
    return 0;
}