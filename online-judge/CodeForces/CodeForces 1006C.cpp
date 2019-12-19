#include <iostream>
#include <algorithm>
using namespace std;

long long arr[200007], sum[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }
    int l = 1, r = n - 1, flag = 0;
    long long sum1 = arr[1], maxn = -1;
    long long sum3 = sum[n] - sum[n - 1];
    for (int i = 1; i <= n; i++)
    {
        if (l - 1 == r)
        {
            break;
        }
        if (sum1 > sum3)
        {
            r--;
            sum3 = sum[n] - sum[r];
            continue;
        }
        else if (sum3 > sum1)
        {
            l++;
            sum1 = sum[l];
            continue;
        }
        else if (sum1 == sum3)
        {
            maxn = max(sum1, maxn);
            r--;
            sum3 = sum[n] - sum[r];
            flag = 1;
        }
    }
    if (flag)
    {
        cout << maxn << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}