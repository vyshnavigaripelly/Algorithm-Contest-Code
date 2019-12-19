#include <iostream>

using namespace std;

long long bitnum[107];

int main()
{
    int cnt = 0;
    long long num = 1;
    while (num <= (int)1e9)
    {
        bitnum[cnt] = num;
        num <<= 1;
        cnt++;
    }
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        int pos = 0;
        while (n && bitnum[pos] <= n)
        {
            n -= bitnum[pos++];
        }
        if (n)
        {
            pos++;
        }
        printf("Case %d: %d\n", cas, pos);
    }
    return 0;
}