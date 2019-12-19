#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long arr[300007], cop[300007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> cop[i];
    }
    sort(arr, arr + n, greater<long long>());
    long long sum = accumulate(arr, arr + n, 0LL);
    for (int i = 0; i < m; i++)
    {
        cout << sum - arr[cop[i] - 1] << endl;
    }
    return 0;
}