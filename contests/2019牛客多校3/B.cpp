#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

char str[N];
int len, arr[N], sum[2 * N + 10], idx[N];

int main()
{
    scanf("%d %s", &len, str);
    int zero = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '0')
            zero++;
    }
    int ans2 = min(zero, len - zero) * 2, ans1 = 0;
    if (zero == len - zero)
    {
        printf("%d %d\n", len, ans2);
        return 0;
    }
    memset(sum, -1, sizeof(sum));
    int current = 0;
    int now[2] = {0};
    for (int i = 0; i < len; i++)
    {
        now[str[i] - '0']++;
        idx[i] = now[1] - now[0];
        if (idx[i] == 0)
        {
            ans1 = max(i + 1, ans1);
        }
        if (sum[idx[i] + len + 1] != -1)
        {
            current = i - sum[idx[i] + len + 1];
        }
        else
        {
            sum[idx[i] + len + 1] = i;
        }
        if (current > ans1)
        {
            ans1 = current;
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}