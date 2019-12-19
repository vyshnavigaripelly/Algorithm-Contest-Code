#include <iostream>
using namespace std;

int arr[200007];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long sum = 0;
    int page = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        page = sum / m;
        cout << page - last << ' ';
        last = page;
    }
    return 0;
}