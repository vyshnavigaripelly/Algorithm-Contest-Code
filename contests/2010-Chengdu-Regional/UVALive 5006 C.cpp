#include <iostream>
#include <algorithm>

using namespace std;

int arr[107], brr[107];

int solve(int a, int b)
{
    int cnt = 0;
    for (int i = 1; i <= max(a, b); i <<= 1)
    {
        cnt += ((a & i) != (b & i)) ? 1 : 0;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        sort(arr, arr + m);
        for (int i = 0; i < n; i++)
        {
            int ans = 0x3f3f3f3f, pos = -1;
            for (int j = 0; j < m; j++)
            {
                int tmp = solve(arr[j], brr[i]);
                if (tmp < ans)
                {
                    ans = tmp;
                    pos = j;
                }
            }
            cout << arr[pos] << endl;
        }
    }
    return 0;
}