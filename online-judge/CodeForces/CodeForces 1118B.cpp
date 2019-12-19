#include <iostream>

using namespace std;

long long arr[200007];

int main()
{
    int n;
    cin >> n;
    long long odd1 = 0, even1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (i % 2 == 0)
        {
            odd1 += arr[i];
        }
        else
        {
            even1 += arr[i];
        }
    }
    long long odd2 = 0, even2 = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            even1 -= arr[i];
            even2 += arr[i - 1];
        }
        else
        {
            odd1 -= arr[i];
            odd2 += arr[i - 1];
        }
        if (even1 + even2 == odd1 + odd2)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}