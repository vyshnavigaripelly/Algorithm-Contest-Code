#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double ans1 = 0, ans2 = 0;
        int n, m, x;
        cin >> n >> m;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            ans1 += x;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            ans2 += x;
        }
        ans1 /= n - 1;
        ans2 /= m;
        if (ans1 == (int)ans1)
        {
            ans1--;
        }
        if (ans2 == (int)ans2)
        {
            ans2++;
        }
        else
        {
            ans2 = (int)ans2 + 1;
        }
        cout << min((int)ans1, (int)ans2) << ' ' << max((int)ans1, (int)ans2) << endl;
    }
    return 0;
}