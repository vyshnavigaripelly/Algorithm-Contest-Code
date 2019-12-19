#include <iostream>

using namespace std;

const int N = 1e5 + 7;

long long arr[N][2], vis[N << 1];
long long maxn[N][2];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i][0]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i][1]);
    }
    for (int i = 1; i <= n; i++)
    {
        maxn[i][0] = arr[i][0];
        maxn[i][1] = arr[i][1];
    }
    maxn[2][0] += maxn[1][1];
    maxn[2][1] += maxn[1][0];
    for (int i = 3; i <= n; i++)
    {
        maxn[i][0] = max(maxn[i][0] + maxn[i - 2][1], maxn[i][0] + maxn[i - 1][1]);
        maxn[i][1] = max(maxn[i][1] + maxn[i - 2][0], maxn[i][1] + maxn[i - 1][0]);
    }
    printf("%lld\n", max(maxn[n][0], maxn[n][1]));
    return 0;
}