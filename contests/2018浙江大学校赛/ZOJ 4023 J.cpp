#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        string ans = b + a;
        ans[0] = toupper(ans[0]);
        cout << ans << endl;
    }
    return 0;
}
