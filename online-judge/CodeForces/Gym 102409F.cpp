#include <iostream>
#include <algorithm>

using namespace std;

char s[30];
int ans[(1 << 20) + 7];

int main()
{
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                ans[i] += s[j];
            }
        }
    }
    sort(ans, ans + (1 << n));
    for (int i = 0; i < (1 << n); i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}