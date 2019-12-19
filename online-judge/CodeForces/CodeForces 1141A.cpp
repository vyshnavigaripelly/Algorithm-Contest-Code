#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (b % a != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int x = b / a;
        int ans = 0;
        while (x % 2 == 0)
        {
            ans++;
            x /= 2;
        }
        while (x % 3 == 0)
        {
            ans++;
            x /= 3;
        }
        if (x != 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}