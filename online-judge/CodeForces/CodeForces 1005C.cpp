#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long arr[130000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int find = 0;
        for (int j = 0; j < 32; j++)
        {
            long long diff = (long long)pow(2, j) - arr[i];
            if (diff <= 0)
            {
                continue;
            }
            int pos = lower_bound(arr, arr + n, diff) - arr;
            if (arr[pos] == diff)
            {
                if (pos == i && arr[pos + 1] == diff)
                {
                    find = 1;
                }
                else if (pos != i)
                {
                    find = 1;
                }
            }
        }
        if (!find)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}