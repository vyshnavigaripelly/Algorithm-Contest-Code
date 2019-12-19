#include <iostream>

using namespace std;

int arr[107];

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (x > y)
    {
        cout << n << endl;
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= x)
            {
                cnt++;
            }
        }
        cout << ((cnt % 2 == 1) ? (cnt / 2 + 1) : (cnt / 2)) << endl;
    }
    return 0;
}