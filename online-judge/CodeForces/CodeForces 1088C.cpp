#include <iostream>

using namespace std;

int arr[2007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << n + 1 << endl;
    cout << 2 << ' ' << n << ' ' << 1 << endl;
    cout << 1 << ' ' << n << ' ' << 2 * n << endl;
    for (int i = 1; i <= n - 1; i++)
    {
        cout << 2 << ' ' << i << ' ' << 2 * n - i << endl;
    }
    return 0;
}