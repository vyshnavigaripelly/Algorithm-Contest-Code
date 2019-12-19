#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        map<int, int> num;
        while (m--)
        {
            int k;
            scanf("%d", &k);
            num[k]++;
        }
        map<int, int>::iterator it;
        int cnt = 0;
        for (it = num.begin(); it != num.end(); it++)
        {
            if (it->first >= 1 && it->first <= n)
            {
                cnt++;
            }
        }
        printf("%d\n", n - cnt);
    }
    return 0;
}
