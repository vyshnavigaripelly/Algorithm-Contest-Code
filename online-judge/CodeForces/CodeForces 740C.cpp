#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0x3f3f3f3f;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        ans = min(ans, r - l + 1);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i % ans << ' ';
    }
    return 0;
}