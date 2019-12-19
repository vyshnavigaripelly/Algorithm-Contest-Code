#include <iostream>
#include <algorithm>

using namespace std;

int arr[107];

int main()
{
    int n, k, maxn = -1, sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (arr[x] == 0)
        {
            sum++;
        }
        arr[x]++;
        maxn = max(maxn, arr[x]);
    }
    int m = k;
    while (k < maxn)
    {
        k += m;
    }
    cout << k * sum - n << endl;
    return 0;
}