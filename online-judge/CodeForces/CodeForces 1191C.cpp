#include <iostream>

using namespace std;

long long arr[100007];

int main()
{
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long cnt = 0, ans = 0;
    while (cnt < m)
    {
        long long pos = (arr[cnt] - cnt + k - 1) / k * k + cnt;
        while (arr[cnt] <= pos && cnt < m)
        {
            cnt++;
        }
        ans++;
    }
    printf("%lld\n", ans);
    return 0;
}