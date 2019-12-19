#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e6 + 7;

char str[N], ans[N << 1];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, cnt = 0;
        char seed[4];
        scanf("%d %s %s", &n, seed, str);
        for (int i = 0; i < n; i++)
        {
            int num = abs((int)(str[i] - seed[0]));
            ans[cnt++] = num / 10;
            ans[cnt++] = num % 10;
        }
        int tmp = 0;
        for (int i = 0; i < cnt - 1; i++)
        {
            if (ans[i] == 0)
                tmp++;
            else
                break;
        }
        cnt -= tmp;
        printf("%d\n", cnt);
    }
    return 0;
}