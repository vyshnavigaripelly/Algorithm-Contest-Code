#include <iostream>

using namespace std;

int arr[307], sum[307];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        int ans = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = a + 1; b <= n; b++)
            {
                if (2 * (sum[b] - sum[a - 1]) != sum[n])
                {
                    continue;
                }
                for (int c = b + 1; c <= n; c++)
                {
                    if (arr[c] == arr[a])
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}