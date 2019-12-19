#include <iostream>

using namespace std;

int arr[200007];

int main()
{
    int n;
    cin >> n;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
    }
    int tmp1 = 0, tmp0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            tmp1++;
        }
        else
        {
            tmp0++;
        }
        if (cnt1 == tmp1 || cnt0 == tmp0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}