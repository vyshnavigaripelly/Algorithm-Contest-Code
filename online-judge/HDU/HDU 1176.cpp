#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[100007][15];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n && n)
    {
        int maxt = -1;
        memset(arr, 0, sizeof(arr));
        while (n--)
        {
            int x, t;
            cin >> x >> t;
            arr[t][x]++;
            maxt = max(t, maxt);
        }
        for (int i = maxt - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 10; j++)
            {
                arr[i][j] += *max_element(&arr[i + 1][j - 1], &arr[i + 1][j - 1] + 3);
            }
        }
        cout << arr[0][5] << endl;
    }
    return 0;
}