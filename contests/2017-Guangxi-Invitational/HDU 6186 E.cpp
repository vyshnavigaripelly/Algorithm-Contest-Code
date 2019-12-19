#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 7;

long long arr[N], preand[N], preor[N], sufand[N], sufor[N];

int main()
{
    int n, q;
    while (~scanf("%d %d", &n, &q))
    {
        long long allxor = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            allxor ^= arr[i];
        }
        preand[1] = preor[1] = arr[1];
        sufand[n] = sufor[n] = arr[n];
        for (int i = 2; i <= n; i++)
        {
            preand[i] = arr[i] & preand[i - 1];
            preor[i] = arr[i] | preor[i - 1];
        }
        for (int i = n - 1; i >= 1; i--)
        {
            sufand[i] = arr[i] & sufand[i + 1];
            sufor[i] = arr[i] | sufor[i + 1];
        }
        while (q--)
        {
            int p;
            scanf("%d", &p);
            long long ansand, ansor, ansxor;
            if (p == 1)
            {
                ansand = sufand[p + 1];
                ansor = sufor[p + 1];
                ansxor = allxor ^ arr[p];
            }
            else if (p == n)
            {
                ansand = preand[p - 1];
                ansor = preor[p - 1];
                ansxor = allxor ^ arr[p];
            }
            else
            {
                ansand = preand[p - 1] & sufand[p + 1];
                ansor = preor[p - 1] | sufor[p + 1];
                ansxor = allxor ^ arr[p];
            }
            printf("%lld %lld %lld\n", ansand, ansor, ansxor);
        }
    }
    return 0;
}