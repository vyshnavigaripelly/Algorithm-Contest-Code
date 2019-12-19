#include <iostream>

using namespace std;

int arr[107];

int main()
{
    int n, k;
    cin >> n >> k;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            sum1++;
        }
        else
        {
            sum2++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int tmp1 = sum1, tmp2 = sum2;
        for (int j = 1; j <= n; j++)
        {
            if ((j - i) % k == 0)
            {
                if (arr[j] == 1)
                {
                    tmp1--;
                }
                else
                {
                    tmp2--;
                }
            }
        }
        ans = max(ans, abs(tmp1 - tmp2));
    }
    cout << ans << endl;
    return 0;
}