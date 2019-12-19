#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt[6][26];
char str[2000007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 6; i++)
        {
            scanf("%s", str);
            for (int j = 0; str[j] != '\0'; j++)
            {
                cnt[i][str[j] - 'a']++;
            }
        }
        char harbin[] = "harbin";
        sort(harbin, harbin + 6);
        int flag = 0;
        do
        {
            flag = 1;
            for (int i = 0; i < 6; i++)
            {
                if (cnt[i][harbin[i] - 'a'] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        } while (next_permutation(harbin, harbin + 6));
        puts(flag ? "Yes" : "No");
    }
    return 0;
}