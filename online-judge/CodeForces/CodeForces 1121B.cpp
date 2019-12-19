#include <iostream>

using namespace std;

int arr[1007], cnt[200007], ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cnt[arr[i] + arr[j]]++;
            ans = max(ans, cnt[arr[i] + arr[j]]);
        }
    }
    cout << ans << endl;
    return 0;
}