#include <iostream>
#include <algorithm>

using namespace std;

int arr[500005], n, k;

int getmin(int x)
{
    long long sum = 0;
    for (int i = 0; i < n && arr[i] <= x; i++)
    {
        sum += x - arr[i];
    }
    return sum <= k;
}

int getmax(int x)
{
    long long sum = 0;
    for (int i = n - 1; i >= 0 && arr[i] >= x; i--)
    {
        sum += arr[i] - x;
    }
    return sum <= k;
}

int main()
{
    while (~scanf("%d %d", &n, &k))
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        sort(arr, arr + n);
        int L = sum / n, R = sum / n;
        if (sum % n != 0)
        {
            R++;
        }
        int l = arr[0], r = L, ansl = arr[0], ansr = arr[0];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (getmin(mid))
            {
                ansl = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        l = R;
        r = arr[n - 1];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (getmax(mid))
            {
                ansr = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", ansr - ansl);
    }
    return 0;
}