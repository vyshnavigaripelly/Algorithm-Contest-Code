#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0;
        while (n--)
        {
            long long x, y;
            cin >> x >> y;
            sum += x * y;
        }
        cout << sum << endl;
    }
    return 0;
}