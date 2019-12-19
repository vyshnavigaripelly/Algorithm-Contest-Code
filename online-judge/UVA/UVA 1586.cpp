#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int len = s.length();
        double m = 0;
        for (int i = 0; i < len; i++)
        {
            double k;
            if (isdigit(s[i]))
            {
                continue;
            }
            if (s[i] == 'C')
            {
                k = 12.01;
            }
            if (s[i] == 'H')
            {
                k = 1.008;
            }
            if (s[i] == 'O')
            {
                k = 16.00;
            }
            if (s[i] == 'N')
            {
                k = 14.01;
            }
            int n = 1;
            if (isdigit(s[i + 1]))
            {
                n = s[i + 1] - '0';
                if (isdigit(s[i + 2]))
                {
                    n = 10 * n + s[i + 2] - '0';
                }
            }
            m += k * n;
        }
        printf("%.3lf\n", m);
    }
    return 0;
}
