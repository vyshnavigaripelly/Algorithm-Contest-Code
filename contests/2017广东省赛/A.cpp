#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

char ans[5] = "9394";

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int cnt = 0;
        char str[5];
        scanf("%s", str);
        for (int i = 0; i < 4; i++)
        {
            cnt += min(abs(str[i] - ans[i]), 10 - abs(str[i] - ans[i]));
        }
        printf("Case #%d: %d\n", cas, cnt);
    }
    return 0;
}