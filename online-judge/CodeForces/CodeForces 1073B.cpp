#include <iostream>
using namespace std;

int arr[200007], brr[200007];
int flag[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
    }
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        if (flag[brr[i]] == 1)
        {
            cout << "0 ";
        }
        else
        {
            while (brr[i] != arr[now])
            {
                flag[arr[now]] = 1;
                now++;
                cnt++;
            }
            cout << cnt << " ";
        }
    }
    return 0;
}