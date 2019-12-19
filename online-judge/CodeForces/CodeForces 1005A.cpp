#include <iostream>
using namespace std;

int arr[1007], ans[1007];

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = -1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            ans[cnt++] = arr[i - 1];
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
