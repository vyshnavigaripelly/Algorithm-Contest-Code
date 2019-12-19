#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[1007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mincost = 0x3f3f3f3f, mint = -1;
    for (int t = 1; t <= 105; t++)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp += min(min(abs(arr[i] - (t - 1)), abs(arr[i] - (t + 1))), abs(arr[i] - t));
        }
        if (tmp < mincost)
        {
            mincost = min(mincost, tmp);
            mint = t;
        }
    }
    cout << mint << ' ' << mincost << endl;
    return 0;
}