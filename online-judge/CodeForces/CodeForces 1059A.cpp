#include <iostream>
using namespace std;

int t[100007], l[100007], ans[100007];

int main()
{
    int n, L, a;
    cin >> n >> L >> a;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> l[i];
    }
    ans[0] = t[0];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = t[i] - (t[i - 1] + l[i - 1]);
    }
    ans[n + 1] = L - (t[n] + l[n]);
    for (int i = 0; i <= n + 1; i++)
    {
        cnt += ans[i] / a;
    }
    cout << cnt << endl;
    return 0;
}