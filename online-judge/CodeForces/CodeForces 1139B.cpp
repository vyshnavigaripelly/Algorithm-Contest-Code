#include <iostream>
#include <algorithm>

using namespace std;

long long arr[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long ans = 0;
    long long last = (1 << 30);
    for (int i = n - 1; i >= 0; i--)
    {
        int tmp = min(arr[i], last);
        ans += tmp;
        last = tmp - 1;
        if (last == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}