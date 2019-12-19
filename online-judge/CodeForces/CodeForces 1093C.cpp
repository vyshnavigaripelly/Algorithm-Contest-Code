#include <iostream>

using namespace std;

long long arr[200007];
long long brr[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> brr[i];
    }
    arr[0] = 0;
    arr[n - 1] = brr[0];
    for (int i = 1; i < n / 2; i++)
    {
        long long tmp = arr[n - i];
        if (brr[i] - arr[i - 1] <= tmp)
        {
            arr[i] = arr[i - 1];
            arr[n - i - 1] = brr[i] - arr[i - 1];
        }
        else
        {
            arr[n - i - 1] = tmp;
            arr[i] = brr[i] - tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}