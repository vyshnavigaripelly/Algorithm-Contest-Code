#include <iostream>
#include <algorithm>

using namespace std;

long long arr[107];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            long long a, b;
            cin >> a >> b;
            arr[i] = a + b;
        }
        sort(arr, arr + n);
        int i = 0;
        long long cnt = 1;
        for (i = 0; i < n; i++)
        {
            cnt *= arr[i];
            if (cnt > m)
            {
                break;
            }
        }
        cout << i << endl;
    }
    return 0;
}