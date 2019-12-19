#include <iostream>
using namespace std;

int arr[105];

int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 2;
    for (int i = 1; i < n; i++)
    {
        int dis = arr[i] - arr[i - 1];
        if (dis == 2 * d)
        {
            ans += 1;
        }
        else if (dis > 2 * d)
        {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}