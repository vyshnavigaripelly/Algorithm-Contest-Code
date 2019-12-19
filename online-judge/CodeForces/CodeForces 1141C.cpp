#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

long long arr[200007];
set<long long> se;

int main()
{
    int n;
    cin >> n;
    arr[0] = 1;
    se.insert(1);
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        se.insert(arr[i]);
    }
    long long minn = *min_element(arr, arr + n),
              maxn = *max_element(arr, arr + n);
    if (maxn - minn != n - 1 || se.size() != n)
    {
        cout << -1 << endl;
    }
    else
    {
        long long d = 1 - minn;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] + d << ' ';
        }
    }
    return 0;
}