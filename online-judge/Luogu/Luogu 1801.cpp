#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 2e5 + 7;

long long add[N], get[N];
priority_queue<long long> a;
priority_queue<long long, vector<long long>, greater<long long>> b;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &add[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &get[i]);
    }
    int getCount = 1;
    for (int i = 1; i <= m; i++)
    {
        a.push(add[i]);
        if (a.size() >= getCount)
        {
            b.push(a.top());
            a.pop();
        }
        while (i == get[getCount])
        {
            printf("%lld\n", b.top());
            getCount++;
            a.push(b.top());
            b.pop();
        }
    }
    return 0;
}