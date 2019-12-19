#include <iostream>
#include <set>

using namespace std;

int main()
{
    int q;
    cin >> q;
    set<int> s;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            s.insert(y);
        }
        else if (x == 2)
        {
            s.erase(y);
        }
        else if (x == 3)
        {
            cout << (s.count(y) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}