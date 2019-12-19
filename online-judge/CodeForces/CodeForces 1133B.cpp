#include <iostream>

using namespace std;

int arr[107];

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    while (n--)
    {
        int x;
        cin >> x;
        if (arr[(k - x % k) % k])
        {
            ans += 2;
            arr[(k - x % k) % k]--;
        }
        else
        {
            arr[x % k]++;
        }
    }
    cout << ans << endl;
}