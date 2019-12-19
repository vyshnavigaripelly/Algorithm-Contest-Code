#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;
const int M = 2e5 + 7;

int arr[M], brr[M];
vector<pair<int, int>> vec[N];
int num[N];
int sum[N];

int check(int x, int Sum)
{
    int res = 0;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            if (i != x / i)
            {
                vec[x].push_back({i, x / i});
                vec[x].push_back({x / i, i});
                res += 2;
            }
            else
            {
                vec[x].push_back({i, x / i});
                res++;
            }
        }
        if (res >= Sum)
            return res;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        brr[i] = arr[i];
        sum[arr[i]]++;
    }
    sort(brr + 1, brr + 1 + n);
    int tot = unique(brr + 1, brr + 1 + n) - brr;
    for (int i = 1; i <= tot; i++)
    {
        int tmp = check(brr[i], sum[brr[i]]);
        if (sum[brr[i]] > tmp)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", vec[arr[i]][num[arr[i]]].first, vec[arr[i]][num[arr[i]]].second);
        num[arr[i]]++;
    }
    return 0;
}