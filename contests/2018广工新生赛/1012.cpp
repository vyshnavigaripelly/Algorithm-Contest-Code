#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[100007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int b;
        cin >> b;
        memset(arr, 0, sizeof(arr));
        int ans = 0;
        for (int i = 1; i <= 1000; i++)
        {
            int k = b / __gcd(b, i);
            if (arr[k] == 0)
            {
                arr[k] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}