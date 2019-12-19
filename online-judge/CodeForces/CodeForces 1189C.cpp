#include <iostream>

using namespace std;

int arr[100007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = arr[r] - arr[l - 1];
        cout << ans / 10 << endl;
    }
    return 0;
}