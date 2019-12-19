#include <iostream>
#include <algorithm>

using namespace std;

int arr[1007];

int main()
{
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sort(arr + 1, arr + 1 + i);
        int sum = 0;
        for (int j = i; j >= 1; j -= 2)
        {
            sum += arr[j];
        }
        if (sum > h)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}