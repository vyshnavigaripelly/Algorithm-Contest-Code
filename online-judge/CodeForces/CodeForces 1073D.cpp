#include <iostream>
using namespace std;

long long arr[200007];
int flag[200007];

int main()
{
    long long n, t, sum = 0, cnt = 0, ans = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= t)
        {
            sum += arr[i];
            flag[i] = 1;
            cnt++;
        }
    }
    while (sum != 0)
    {
        ans += cnt * (t / sum);
        t -= sum * (t / sum);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > t && flag[i])
            {
                sum -= arr[i];
                flag[i] = 0;
                cnt--;
            }
        }
        if (sum == 0)
        {
            break;
        }
        if (t / sum == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (flag[i] && t >= arr[i])
                {
                    ans++;
                    t -= arr[i];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}