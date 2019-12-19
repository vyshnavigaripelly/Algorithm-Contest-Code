#include <iostream>

using namespace std;

int arr[10007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        last = max(last, arr[i]);
        if (last == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}