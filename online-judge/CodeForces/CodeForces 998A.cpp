#include <iostream>
using namespace std;

int arr[15];

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (n == 1)
    {
        cout << -1 << endl;
    }
    else if (n == 2)
    {
        if (arr[1] == arr[2])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << 1 << endl
                 << 1 << endl;
        }
    }
    else
    {
        int minx = 6666, minpos = -1;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] < minx)
            {
                minx = arr[i];
                minpos = i;
            }
        }
        cout << 1 << endl
             << minpos << endl;
    }
    return 0;
}