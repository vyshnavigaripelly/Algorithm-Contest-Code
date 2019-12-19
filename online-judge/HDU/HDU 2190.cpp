#include <iostream>
using namespace std;

int main()
{
    int arr[31] = {0, 1, 3};
    for (int i = 3; i <= 30; i++)
    {
        arr[i] = 2 * arr[i - 2] + arr[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}
