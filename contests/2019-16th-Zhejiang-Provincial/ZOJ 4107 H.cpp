#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n + 1; i++)
        {
            cin >> arr[i];
        }
        int cnt = 0;
        arr[0] = arr[1] = arr[n + 2] = arr[n + 3] = (1LL << 62);
        for (int i = 3; i <= n; i++)
        {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
            {
                cnt++;
            }
        }
        int ans = cnt;
        for (int i = 2; i <= n + 1; i++)
        {
            int bef = 0, aft = 0;
            auto check = [](int j) {
                return arr[j - 1] < arr[j] && arr[j] > arr[j + 1];
            };
            bef += check(i - 1) + check(i) + check(i + 1);
            if (arr[i - 2] < arr[i - 1] && arr[i - 1] > arr[i + 1])
            {
                aft++;
            }
            if (arr[i - 1] < arr[i + 1] && arr[i + 1] > arr[i + 2])
            {
                aft++;
            }
            ans = min(ans, cnt - bef + aft);
        }
        cout << ans << endl;
    }
    return 0;
}