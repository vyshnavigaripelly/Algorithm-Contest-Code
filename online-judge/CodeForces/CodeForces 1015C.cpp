#include <iostream>
#include <algorithm>
using namespace std;

int diff[1000007];

int main()
{
    long long n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int be, af;
        cin >> be >> af;
        diff[i] = be - af;
        sum += be;
    }
    sort(diff, diff + n, greater<int>());
    int i, ans = 0;
    if (sum <= m)
    {
        cout << 0 << endl;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            sum -= diff[i];
            ans++;
            if (sum <= m)
            {
                break;
            }
        }
        if (i == n)
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