#include <bits/stdc++.h>

using namespace std;

const int Maxn = 4e7 + 7;

bool check[Maxn];
int phi[Maxn];
long long ans[Maxn];
int prime[Maxn];
int tot;

void phi_tab(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

int main()
{
    phi_tab(Maxn);
    for (int i = 1; i <= Maxn / 2; i++)
    {
        ans[i] = ans[i - 1] + phi[i * 2] / 2;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}