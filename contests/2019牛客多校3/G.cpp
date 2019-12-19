#include <iostream>
#include <cmath>

using namespace std;

const int N = 3e5 + 7;

long long arr[N], presum[N], sufsum[N];
int st[N][20];
long long ans;
int n;

void stinit()
{
    for (int i = 1; i <= n; i++)
        st[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            int a = st[i][j - 1], b = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = arr[a] > arr[b] ? a : b;
        }
    }
}

int stquery(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    int a = st[l][k], b = st[r - (1 << k) + 1][k];
    return arr[a] > arr[b] ? a : b;
}

void solve(int l, int r)
{
    if (l >= r)
        return;
    if (r - l + 1 == 2)
    {
        if (arr[l] == arr[r])
            ans++;
        return;
    }
    int mid = stquery(l, r);
    if (mid - l + 1 < r - mid + 1)
    {
        for (int i = l; i <= mid; i++)
        {
            int pos = lower_bound(presum + mid, presum + r + 1, presum[i - 1] + arr[mid] * 2) - presum;
            ans += r - pos + 1;
        }
    }
    else
    {
        for (int i = mid; i <= r; i++)
        {
            int pos = lower_bound(sufsum + n + 1 - mid, sufsum + n + 1 - l + 1, sufsum[n + 1 - (i + 1)] + arr[mid] * 2) - sufsum;
            ans += n + 1 - l - (pos - 1);
        }
    }
    solve(l, mid - 1);
    solve(mid + 1, r);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            presum[i] = presum[i - 1] + arr[i];
            sufsum[i] = sufsum[i - 1] + arr[n + 1 - i];
        }
        stinit();
        ans = 0;
        solve(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}