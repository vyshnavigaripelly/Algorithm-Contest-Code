#include <iostream>

using namespace std;


int arr[107], sub[107];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = 1001;
    arr[n + 2] = 9999;
    int l = 0, r = 0, maxl = -1, maxr = -1, maxn = 0, len = 0;
    for (int i = 1; i <= n + 2; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            r = i;
        }
        else
        {
            if (r - l - 1 >= maxn)
            {
                maxn = r - l - 1;
                maxl = l;
                maxr = r;
            }
            l = i;
        }
    }
    cout << maxn << endl;
    return 0;
}