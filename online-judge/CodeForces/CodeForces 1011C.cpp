#include <iostream>
#include <cstdio>
using namespace std;

int a[1100], b[1100];
const double eps = 1e-10;

int main()
{
    int n, m;
    cin >> n >> m;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            flag = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        double left = 0, right = 1e9, mid;
        while (right - left > eps)
        {
            mid = (left + right) / 2;
            double rest = m + mid;
            for (int i = 1; i < n; i++)
            {
                rest -= rest / a[i - 1];
                rest -= rest / b[i];
            }
            rest -= rest / a[n - 1];
            rest -= rest / b[0];
            if (rest < m)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        printf("%.7f\n", mid);
    }
    return 0;
}
