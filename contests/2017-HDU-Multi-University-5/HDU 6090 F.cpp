#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, full;
        cin >> n >> m;
        full = n * (n - 1) / 2;
        if (m >= full)
        {
            cout << n * (n - 1) << endl;
        }
        else if (m >= n - 1)
        {
            cout << n * (n - 1) + (full - m) * 2 << endl;
        }
        else
        {
            cout << 2 * m * m + (n - m - 1) * ((n - m - 1) - 1) * n + (n - m - 1) * (m + 1) * n * 2 << endl;
        }
    }
    return 0;
}