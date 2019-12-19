#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans1 = 0, ans2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int q;
            cin >> q;
            if (i == 1)
                ans1 = q;
            else if (i == n)
                ans2 = q;
        }
        if (n == 1)
            cout << 0 << endl;
        else
            cout << (int)sqrt(abs(ans1 - ans2)) << endl;
    }
}