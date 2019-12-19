#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long in, sum = 0, max = 0;
        cin >> n;
        while (n--)
        {
            cin >> in;
            sum += in;
            if (in > max)
            {
                max = in;
            }
        }
        sum -= max;
        if (max - sum >= 2)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
