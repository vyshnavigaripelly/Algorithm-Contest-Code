#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        int flag = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            long long s = i;
            while (s < n)
            {
                s *= i;
                if (s == n)
                {
                    flag = 1;
                }
            }
        }
        cout << (flag ? "yes" : "no") << endl;
    }
    return 0;
}