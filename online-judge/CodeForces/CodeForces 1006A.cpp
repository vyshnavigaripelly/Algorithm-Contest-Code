#include <iostream>
using namespace std;

int arr[1050];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            cout << arr[i] << ' ';
        }
        else
        {
            cout << arr[i] - 1 << ' ';
        }
    }
    return 0;
}