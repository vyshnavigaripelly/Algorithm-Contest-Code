#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double E = exp(1);

double arr[107];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] /= 100.0;
        }
        double c;
        if (s == "bit")
        {
            c = 2;
        }
        else if (s == "nat")
        {
            c = E;
        }
        else if (s == "dit")
        {
            c = 10;
        }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                ans += arr[i] * log10(arr[i]) / log10(c);
            }
        }
        printf("%.12f\n", -ans);
    }
    return 0;
}