#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

int sum[1000007], maxsum[1000007];

int main()
{
    int t;
    while (~scanf("%d", &t))
    {
        stack<int> pre, suf;
        char c;
        int x, pos = 0;
        maxsum[0] = -(1 << 30);
        while (t--)
        {
            getchar();
            scanf("%c", &c);
            if (c == 'I')
            {
                scanf("%d", &x);
                pos++;
                pre.push(x);
                sum[pos] = sum[pos - 1] + x;
                maxsum[pos] = max(maxsum[pos - 1], sum[pos]);
            }
            else if (c == 'D')
            {
                pos--;
                pre.pop();
            }
            else if (c == 'L')
            {
                if (!pre.empty())
                {
                    pos--;
                    suf.push(pre.top());
                    pre.pop();
                }
            }
            else if (c == 'R')
            {
                if (!suf.empty())
                {
                    pos++;
                    pre.push(suf.top());
                    suf.pop();
                    sum[pos] = sum[pos - 1] + pre.top();
                    maxsum[pos] = max(maxsum[pos - 1], sum[pos]);
                }
            }
            else if (c == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", maxsum[x]);
            }
        }
    }
    return 0;
}