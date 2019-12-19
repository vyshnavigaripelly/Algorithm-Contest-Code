#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                sum += i;
                int k = n / i;
                if (k != i)
                {
                    sum += k;
                }
            }
        }
        cout << sum - n << endl;
    }
    return 0;
}
