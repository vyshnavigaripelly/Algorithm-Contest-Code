#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const double eps = 1e-8;

int s[N], c[N];
double arr[N];
double mid, l, r, ans;
int n, k;

int check()
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] = -(1.0 * s[i] * c[i] - mid * s[i]);
    }
    sort(arr + 1, arr + 1 + n);
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= eps && i > (n - k))
        {
            break;
        }
        sum += (-arr[i]);
    }
    if (sum >= eps)
        return 1;
    return 0;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    l = 0, r = 1000000;
    while ((r - l) > eps)
    {
        mid = (l + r) / 2.0;
        if (check())
        {
            ans = max(ans, mid);
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.8f\n", ans);
    return 0;
}