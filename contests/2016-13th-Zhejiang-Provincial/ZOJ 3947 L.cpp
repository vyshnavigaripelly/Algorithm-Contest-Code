#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = n;
        while (n--)
        {
            int k;
            cin >> k;
            ans += k;
        }
        cout << ans << endl;
    }
    return 0;
}