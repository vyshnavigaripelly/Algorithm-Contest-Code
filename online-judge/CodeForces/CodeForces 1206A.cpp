#include <iostream>

using namespace std;

const int N = 107;

int arr[N], brr[N], cnt[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> brr[i];
        cnt[brr[i]]++;
    }
    int flag = 0;
    for (int i = 1; i <= n && !flag; i++)
    {
        for (int j = 1; j <= m && !flag; j++)
        {
            if (cnt[arr[i] + brr[j]] == 0)
            {
                cout << arr[i] << ' ' << brr[j];
                flag = 1;
            }
        }
    }
    return 0;
}