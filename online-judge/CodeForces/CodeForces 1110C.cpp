#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a;
        cin >> a;
        if ((a & (a + 1)) == 0)
        {
            int found = 0;
            for (long long i = 2; i * i <= a; i++)
            {
                if (a % i == 0)
                {
                    cout << a / i << endl;
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                cout << 1 << endl;
            }
        }
        else
        {
            long long ans = 1;
            while (ans < a)
            {
                ans = ans * 2 + 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}