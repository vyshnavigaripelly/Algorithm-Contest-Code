#include <iostream>
#include <cstdio>
#include <stack>
#include <map>

using namespace std;

int h[100007];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        stack<pair<int, int>> s;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &h[i]);
        }
        h[0] = h[n + 1] = 0;
        long long ans = 0;
        s.push(make_pair(0, 1));
        for (int i = 1; i <= n + 1; i++)
        {
            if (h[i] > s.top().first)
            {
                s.push(make_pair(h[i], 1));
            }
            else
            {
                long long width = 0;
                while (s.top().first > h[i])
                {
                    width += s.top().second;
                    ans = max(ans, width * s.top().first);
                    s.pop();
                }
                s.push(make_pair(h[i], width + 1));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}