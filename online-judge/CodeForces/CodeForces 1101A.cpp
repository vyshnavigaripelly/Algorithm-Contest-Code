#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, d;
        cin >> l >> r >> d;
        int ans = r / d;
        if (l > d)
        {
            cout << d << endl;
        }
        else
        {
            cout << (ans + 1) * d << endl;
        }
    }
    return 0;
}