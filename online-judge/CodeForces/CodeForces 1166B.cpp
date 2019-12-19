#include <iostream>
#include <cstring>

using namespace std;

char mp[1007][1007];

int main()
{
    int n;
    cin >> n;
    if (n < 25)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0 && i >= 5 && n / i >= 5)
            {
                for (int r = 0; r < i; r++)
                {
                    for (int c = 0; c < n / i; c++)
                    {
                        cout << "aeiou"[(r + c) % 5];
                    }
                }
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}