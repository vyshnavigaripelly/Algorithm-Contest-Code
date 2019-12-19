#include <iostream>
using namespace std;

int arr[1007], brr[1007];

int main()
{
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
    }
    int flag = 0;
    for (int i = s; i <= n; i++)
    {
        if (arr[i] && brr[i])
        {
            flag = 1;
        }
    }
    if (arr[1] && (arr[s] || (brr[s] && flag)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}