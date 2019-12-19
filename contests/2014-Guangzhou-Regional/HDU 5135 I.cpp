#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double S(double x, double y, double z)
{
    double p = (x + y + z) / 2;
    double anss = sqrt(p * (p - x) * (p - y) * (p - z));
    return anss;
}

double arr[107];

int main()
{
    int n;
    while (cin >> n && n)
    {
        double ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        sort(arr + 1, arr + 1 + n);
        for (int i = n; i >= 1; i--)
        {
            double tmp = arr[i];
            int flag = 0;
            for (int j = i - 1; j >= 2; j--)
            {
                double tmp2 = arr[j];
                for (int k = j - 1; k >= 1; k--)
                {
                    double tmp3 = arr[k];
                    if (tmp < tmp2 + tmp3 && tmp - tmp3 < tmp2)
                    {
                        ans += S(tmp, tmp2, tmp3);
                        i = k;
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                continue;
        }
        printf("%.2f\n", ans);
    }
}