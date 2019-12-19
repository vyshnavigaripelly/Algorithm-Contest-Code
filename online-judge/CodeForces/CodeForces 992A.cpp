#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        int k;
        cin >> k;
        if (k != 0)
        {
            s.insert(k);
        }
    }
    cout << s.size() << endl;
    return 0;
}