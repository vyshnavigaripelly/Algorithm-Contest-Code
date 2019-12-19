#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

double arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &arr[i]);
        }
        sort(arr, arr + n);
        if (arr[0] >= 0.5)
        {
            printf("%.8f\n", arr[n - 1]);
            continue;
        }
        int st = n - 1;
        for (; st >= 0; st--)
        {
            if (arr[st] < 0.5)
            {
                break;
            }
        }
        double maxn = arr[n - 1];
        double unhappy = 1, tmpans = 0, ans = 0;
        for (; st >= 0; st--)
        {
            tmpans *= (1 - arr[st]);
            tmpans += (unhappy * arr[st]);
            if (tmpans < ans)
            {
                break;
            }
            ans = tmpans;
            unhappy *= (1 - arr[st]);
        }
        ans = max(maxn, ans);
        printf("%.8f\n", ans);
    }
    return 0;
}