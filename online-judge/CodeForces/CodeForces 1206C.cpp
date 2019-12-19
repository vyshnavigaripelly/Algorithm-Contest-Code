#include <iostream>

using namespace std;

const int N = 1e5 + 7;

long long arr[N][2];
long long ans[2 * N];

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1, j = 1; i <= 2 * n; i += 2, j++)
    {
        if (i / 2 % 2 != 0)
        {
            arr[j][0] = i + 1;
            arr[j][1] = i;
        }
        else
        {
            arr[j][0] = i;
            arr[j][1] = i + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = arr[i][0];
    }
    for (int i = n + 1, j = 1; i <= 2 * n; i++, j++)
    {
        ans[i] = arr[j][1];
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}