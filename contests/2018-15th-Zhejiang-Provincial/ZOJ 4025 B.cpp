#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

int a[maxn], b[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        map<int, int> m;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            m[a[i] - b[i]]++;
        }
        int max = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > max)
            {
                max = it->second;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
