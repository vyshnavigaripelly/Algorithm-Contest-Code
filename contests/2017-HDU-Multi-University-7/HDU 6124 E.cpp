#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans;
        cin >> n;
        ans = n;
        if (n % 2 == 1)
            ans = n + 1;
        ans = ans / 2 + 1;
        cout << ans << endl;
    }
    return 0;
}