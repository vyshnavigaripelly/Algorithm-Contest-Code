#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cout << i << ' ' << (3 * n - 3) + i - 1 << ' ';
        }
        if (n % 2 != 0)
        {
            cout << n << ' ' << 3 * n - 4 << endl;
        }
        else
        {
            cout << 0 << ' ' << n - 1 + n / 2 << endl;
        }
    }
    return 0;
}
