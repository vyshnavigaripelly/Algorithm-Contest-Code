#include <iostream>

using namespace std;

int arr[100007];

int main()
{
    int n;
    cin >> n;
    int sgn = 1, cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= -1)
        {
            ans -= arr[i] + 1;
            sgn *= -1;
        }
        else if (arr[i] >= 1)
        {
            ans += arr[i] - 1;
            sgn *= 1;
        }
        else
        {
            cnt++;
        }
    }
    if (sgn == -1 && cnt == 0)
    {
        ans += 2;
    }
    else
    {
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}
