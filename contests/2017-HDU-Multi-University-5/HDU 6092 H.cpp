#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long b[10007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= m; i++)
        {
            scanf("%lld", &b[i]);
        }
        vector<int> ans;
        for (int i = 1; i <= m;)
        {
            if (ans.size() > n)
            {
                break;
            }
            if (b[i] != 0)
            {
                ans.push_back(i);
                for (int j = i; j <= m; j++)
                {
                    b[j] -= b[j - i];
                }
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        }
    }
    return 0;
}