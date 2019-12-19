#include <iostream>
#include <cstring>

using namespace std;

char str[10][20];
int len[10];
char ans[10], tmp[10];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
            for (int j = 0; j < len[i]; j++)
            {
                str[i][j + len[i]] = str[i][j];
            }
            str[i][2 * len[i]] = '\0';
        }
        int tmplen = 0, anslen = 0;
        for (int start = 0; start < len[0]; start++)
        {
            for (int i = 1; i < (1 << len[0]); i++)
            {
                tmplen = 0;
                for (int j = 0; j < len[0]; j++)
                {
                    if (i & (1 << j))
                    {
                        tmp[tmplen++] = str[0][start + j];
                        tmp[tmplen] = '\0';
                    }
                }
                int flag = 1;
                for (int j = 1; j < n; j++)
                {
                    int flag2 = 0;
                    for (int start2 = 0; start2 < len[j]; start2++)
                    {
                        int now = 0;
                        for (int k = 0; k < len[j]; k++)
                        {
                            if (str[j][start2 + k] == tmp[now])
                                now++;
                        }
                        if (now == tmplen)
                        {
                            flag2 = 1;
                            break;
                        }
                    }
                    if (flag2 == 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1)
                {
                    if (tmplen > anslen || (tmplen == anslen && strcmp(tmp, ans) < 0))
                    {
                        strcpy(ans, tmp);
                        anslen = tmplen;
                    }
                }
            }
        }
        if (anslen == 0)
            puts("0");
        else
            puts(ans);
    }
    return 0;
}