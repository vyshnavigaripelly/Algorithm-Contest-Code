#include <iostream>
#include <algorithm>

using namespace std;

int need[1007], has[1007];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> need[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> has[i];
    }
    int ans = 0;
    for (ans = 0;; ans++)
    {
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t += max(0, need[i] * ans - has[i]);
        }
        if (t > k)
        {
            break;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}