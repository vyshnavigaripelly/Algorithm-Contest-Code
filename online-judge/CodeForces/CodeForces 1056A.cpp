#include <iostream>

using namespace std;

int arr[107];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        while (r--)
        {
            int k;
            cin >> k;
            arr[k]++;
        }
    }
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i] == n)
        {
            cout << i << ' ';
        }
    }
    return 0;
}