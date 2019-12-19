#include <iostream>
#include <algorithm>

using namespace std;

int arr[1007];

int main()
{
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0, last = 0;
    while (last < n)
    {
        int pos = 0;
        for (int i = n; i >= max(0, last - r + 2); i--)
        {
            if (arr[i] == 1 && i - r <= last)
            {
                pos = i;
                break;
            }
        }
        if (pos == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans++;
            last = pos + r - 1;
        }
    }
    cout << ans << endl;
    return 0;
}