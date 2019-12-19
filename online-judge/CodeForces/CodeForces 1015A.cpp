#include <iostream>
using namespace std;

int arr[107];

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = 1;
                cnt--;
            }
        }
    }
    cout << cnt << endl;
    if (cnt != 0)
    {
        for (int i = 1; i <= m; i++)
        {
            if (arr[i] == 0)
            {
                cout << i << ' ';
            }
        }
    }
    return 0;
}