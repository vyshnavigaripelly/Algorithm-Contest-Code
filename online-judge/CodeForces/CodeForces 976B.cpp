#include <iostream>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    if (k < n)
    {
        cout << k + 1 << ' ' << 1 << endl;
    }
    else
    {
        long long rest = k - n, c = rest / (m - 1);
        if (c % 2 == 0)
        {
            cout << n - c << ' ' << 2 + rest % (m - 1) << endl;
        }
        else
        {
            cout << n - c << ' ' << 1 + (m - 1) - rest % (m - 1) << endl;
        }
    }
    return 0;
}
