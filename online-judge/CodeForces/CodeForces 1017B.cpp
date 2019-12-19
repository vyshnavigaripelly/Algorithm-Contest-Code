#include <iostream>
#include <string>
using namespace std;

long long cnt1, cnt2, cnt3, cnt4;

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0' && a[i] == '0')
        {
            cnt1++;
        }
        if (b[i] == '0' && a[i] == '1')
        {
            cnt2++;
        }
        if (a[i] == '1')
        {
            cnt3++;
        }
        else
        {
            cnt4++;
        }
    }
    long long ans = cnt2 * cnt4 + cnt1 * cnt3 - cnt1 * cnt2;
    cout << ans << endl;
    return 0;
}