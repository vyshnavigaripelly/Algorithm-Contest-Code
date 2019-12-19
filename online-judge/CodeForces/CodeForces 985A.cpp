#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int arr[150], n, black = 0, white = 0;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n / 2);
    for (int i = 1, j = 1; i <= n / 2; i++, j += 2)
    {
        black += abs(arr[i] - j);
    }
    for (int i = 1, j = 2; i <= n / 2; i++, j += 2)
    {
        white += abs(arr[i] - j);
    }
    cout << min(black, white) << endl;
    return 0;
}
