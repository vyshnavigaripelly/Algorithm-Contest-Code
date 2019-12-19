#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    const double PI = 3.14159;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        double s, max = 0;
        cin >> n;
        while (n--)
        {
            char type;
            int a, b;
            cin >> type;
            switch (type)
            {
                case 'T':
                {
                    cin >> a >> b;
                    s = a * b / 2.0;
                    break;
                }
                case 'R':
                {
                    cin >> a >> b;
                    s = a * b;
                    break;
                }
                case 'C':
                {
                    cin >> a;
                    s = PI * a * a;
                    break;
                }
            }
            if (s > max)
            {
                max = s;
            }
        }
        printf("%.2f\n", max);
    }
    return 0;
}
