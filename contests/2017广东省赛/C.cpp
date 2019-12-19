#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 7;

long long sumk[N], sumb[N];

struct Node
{
    long long type, cost, pos, k, b;
} arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            sumk[i] = sumb[i] = 0;
            char s[10];
            long long k, b;
            scanf("%s %lld %lld %lld", s, &arr[i].cost, &arr[i].pos, &k);
            b = -arr[i].cost;
            if (s[0] == 'C')
            {
                arr[i].type = 1;
            }
            else
            {
                arr[i].type = -1;
                k = -k;
            }
            arr[i].k = k;
            arr[i].b = -(arr[i].pos * k - b);
        }
        sumk[n + 1] = sumk[n + 2] = sumb[n + 1] = sumb[n + 2] = 0;
        sort(arr + 1, arr + 1 + n, [](const Node &a, const Node &b) {
            return a.pos < b.pos || (a.pos == b.pos && a.type > b.type);
        });
        for (int i = 1; i <= n; i++)
        {
            sumk[1] += (arr[i].type == 1 ? 0 : arr[i].k);
            sumb[1] += (arr[i].type == 1 ? -arr[i].cost : arr[i].b);
        }
        for (int i = 2; i <= n + 1; i++)
        {
            sumk[i] = sumk[i - 1];
            sumb[i] = sumb[i - 1];
            if (arr[i - 1].type == -1)
            {
                sumk[i] -= arr[i - 1].k;
                sumb[i] -= arr[i - 1].b;
                sumb[i] += -arr[i - 1].cost;
            }
            else
            {
                sumk[i] += arr[i - 1].k;
                sumb[i] -= -arr[i - 1].cost;
                sumb[i] += arr[i - 1].b;
            }
        }
        arr[n + 1].pos = (1LL << 62);
        printf("Case #%d:\n", cas);
        for (int i = 1; i <= n + 1; i++)
        {
            if (arr[i - 1].pos == arr[i].pos)
            {
                continue;
            }
            if (i == n + 1)
            {
                printf("[%lld,...] b=", arr[i - 1].pos);
            }
            else
            {
                printf("[%lld,%lld] b=", arr[i - 1].pos, arr[i].pos);
            }
            if (sumk[i] != 0 && sumb[i] == 0)
            {
                printf("%lld*x", sumk[i]);
            }
            else if (sumk[i] == 0)
            {
                printf("%lld", sumb[i]);
            }
            else
            {
                printf("%lld*x", sumk[i]);
                if (sumb[i] > 0)
                {
                    printf("+%lld", sumb[i]);
                }
                else
                {
                    printf("%lld", sumb[i]);
                }
            }
            puts("");
        }
    }
    return 0;
}