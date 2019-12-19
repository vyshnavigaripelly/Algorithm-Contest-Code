#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2e5 + 7;

char a[N], b[N], ans[N];

int main()
{
    int n;
    scanf("%d %s %s", &n, a, b);
    for (int i = 0; i < n; i++)
    {
        a[i] -= 'a';
        b[i] -= 'a';
        ans[i + 1] = a[i] + b[i];
    }
    for (int i = n; i >= 1; i--)
    {
        ans[i - 1] += ans[i] / 26;
        ans[i] %= 26;
    }
    int tmp = 0;
    for (int i = 0; i <= n; i++)
    {
        tmp = tmp * 26 + ans[i];
        ans[i] = tmp / 2 + 'a';
        tmp %= 2;
    }
    printf("%s\n", ans + 1);
    return 0;
}