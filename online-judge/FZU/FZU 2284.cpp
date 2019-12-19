#include <iostream>
using namespace std;

int main()
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;
            cout << ((n >= 4) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
