#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 7;

int arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, a, b;
        int num = 0;
        long long ans = 0xcfcfcfcfcfcfcfcf;
        scanf("%d %d %d", &n, &a, &b);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + 1 + n);
        int flag = 1;
        vector<long long> vec;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 2 || i == n || i == n - 1)
            {
                vec.push_back(arr[i]);
            }
            else if (arr[i] == 0 && num <= 2)
            {
                vec.push_back(arr[i]);
                num++;
            }
            else if (arr[i - 1] < 0 && arr[i + 1] > 0 && flag)
            {
                vec.push_back(arr[i]);
                if (i - 1 != 2)
                {
                    vec.push_back(arr[i - 1]);
                }
                if (i + 1 != n - 1)
                {
                    vec.push_back(arr[i + 1]);
                }
                flag = 0;
            }
        }
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (i == j)
                    continue;
                ans = max(ans, 1LL * a * vec[i] * vec[i] + 1LL * b * vec[j]);
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
