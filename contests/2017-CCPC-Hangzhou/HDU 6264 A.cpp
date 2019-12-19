#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char str[107];
int cnt[30], cnt2[30];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i += 2)
        {
            cnt[str[i] - 'a']++;
        }
        for (int i = 1; i < len; i += 2)
        {
            cnt2[str[i] - 'a']++;
        }
        int max1 = *max_element(cnt, cnt + 26),
            max2 = *max_element(cnt2, cnt2 + 26);
        int ans = len - max1 - max2;
        printf("%d\n", ans);
    }
    return 0;
}