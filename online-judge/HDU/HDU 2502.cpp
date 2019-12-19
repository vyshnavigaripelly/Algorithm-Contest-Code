#include <iostream>
using namespace std;

int main()
{
    // 1    1   0 1
    // 2    1 + 2**(2-1) = 3    10 11
    // 3    4 + 2**(3-1) = 8    100 101 110 111
    // 4    12 + 2**(4-1) = 20  1000 1001 1010 1011
    //                          1100 1101 1110 1111
    // 5    32 + 2**(5-1) = 48
    long long arr[21] = {0, 1, 3}, sum = 4;
    for (int i = 3; i <= 20; i++)
    {
        arr[i] = sum + (1 << (i - 1));
        sum += arr[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}
