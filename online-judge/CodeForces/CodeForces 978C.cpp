#include <iostream>
#include <algorithm>
using namespace std;

long long arr[233333], let[233333], ans[233333] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &let[i]);
    }
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        long long r, c;
        r = lower_bound(arr, arr + n, let[i]) - arr + 1;
        c = let[i] - arr[r - 2];
        cout << r << ' ' << c << endl;
    }
    return 0;
}
