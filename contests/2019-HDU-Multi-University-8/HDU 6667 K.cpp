#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 7;

struct node
{
    long long num, val;
} arr[N];

bool cmp(node a, node b)
{
    return a.num != b.num ? a.num > b.num : a.val > b.val;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &arr[i].num, &arr[i].val);
        }
        sort(arr + 1, arr + 1 + n, cmp);
        int pos = 1;
        long long sum = 0;
        long long ans = 0;
        int flag = 0;
        for (int i = 2; i <= n; i++)
        {
            sum += arr[i].val;
            while (sum >= arr[pos].num && pos < i)
            {
                sum -= arr[pos].num;
                ans += arr[pos].num;
                if (!flag)
                    sum += arr[pos].val;
                pos++;
                flag = 1;
            }
            if (arr[pos].num >= sum && pos != i)
            {
                arr[pos].num -= sum;
                ans += sum;
                sum = 0;
            }
            if (i == n)
            {
                if (!flag)
                    sum = arr[pos].val;
                for (int j = min(pos + 1, n); j <= n; j++)
                {
                    if (sum >= arr[j].num)
                    {
                        ans += arr[j].num;
                        sum -= arr[j].num;
                    }
                    else
                    {
                        ans += sum;
                        sum = 0;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}