#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        double ans = 1.0 / (2 * n - 1) * (n + 3 * n - 2) * (3 * n - 2 - n + 1) / 2;
        printf("%.2f\n", ans);
    }
    return 0;
}
