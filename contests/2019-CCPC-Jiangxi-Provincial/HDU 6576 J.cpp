#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 7;

int n;
__int128 m;
int arr[N];
unordered_set<int> rk;

__int128 check(__int128 mul)
{
    __int128 cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = cnt + mul * arr[i];
    }
    return cnt;
}

int main()
{
    long long mm;
    long long g = -1;
    __int128 lcm;
    scanf("%d%lld", &n, &mm);
    m = mm;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        rk.insert(arr[i]);
    }
    for (auto i : rk)
    {
        if (g == -1)
        {
            g = i;
            lcm = i;
        }
        else
        {
            g = __gcd((long long)lcm, 1LL * i);
            lcm = (lcm * i) / g;
        }
    }
    //cout << (long long)lcm << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = lcm / arr[i];
    }
    __int128 l = 1;
    __int128 r = m;
    int flag = 0;
    while (l <= r)
    {
        __int128 mid = (l + r) >> 1;
        __int128 cnt = check(mid);
        if (cnt == m)
        {
            flag = 1;
            break;
        }
        else if (cnt < m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (flag)
    {
        puts("Yes");
        __int128 mul = (l + r) >> 1;
        for (int i = 0; i < n; i++)
        {
            printf("%llu", (unsigned long long)mul * arr[i]);
            if (i != n - 1)
            {
                printf(" ");
            }
        }
        puts("");
    }
    else
    {
        puts("No");
    }
    return 0;
}