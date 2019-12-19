#include <iostream>
#include <algorithm>

using namespace std;

int arr[1007];

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    int tmp = (n + 1) / 2;
    sort(arr + 1, arr + 1 + k);
    for (int i = k; i >= 1; i--)
    {
        ans = ans + min(arr[i] / 2, tmp);
        tmp -= arr[i] / 2;
        if (tmp <= 0)
        {
            break;
        }
    }
    cout << 2 * ans + max(tmp, 0) << endl;
    return 0;
}