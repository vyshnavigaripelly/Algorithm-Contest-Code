#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e5 + 7;

struct Node
{
    long long y;
    int k;
} arr[N * 3];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long l, r;
        scanf("%lld %lld", &l, &r);
        arr[i * 3] = {l * 2, 1};
        arr[i * 3 + 1] = {l + r, -2};
        arr[i * 3 + 2] = {r * 2, 1};
    }
    sort(arr, arr + 3 * n, [](const Node &a, const Node &b) {
        return a.y < b.y;
    });
    long long k = 0, sum = 0, ans = 0;
    for (int i = 0; i < 3 * n; i++)
    {
        k += arr[i].k;
        sum += k * (arr[i + 1].y - arr[i].y);
        ans = max(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}