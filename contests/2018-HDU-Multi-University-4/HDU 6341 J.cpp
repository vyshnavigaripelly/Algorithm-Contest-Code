#include <iostream>
#include <cstring>

using namespace std;

char block[5][20][10][10];
int flag[20], ans;

bool check(int blockid)
{
    int strow = blockid, stcol = blockid, tmp;
    while (strow > 4)
        strow -= 4;
    while (stcol % 4 != 1)
        stcol--;
    if (strow != blockid)
    {
        for (int i = 1; i <= 4; i++)
        {
            int apper[20] = {0};
            tmp = strow;
            for (tmp; tmp <= blockid; tmp += 4)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (!apper[block[flag[tmp]][tmp][j][i]])
                        apper[block[flag[tmp]][tmp][j][i]]++;
                    else
                        return false;
                }
            }
        }
    }
    if (stcol != blockid)
    {
        for (int i = 1; i <= 4; i++)
        {
            int apper[20] = {0};
            tmp = stcol;
            while (tmp <= blockid)
            {
                for (int j = 1; j <= 4; j++)
                {
                    if (!apper[block[flag[tmp]][tmp][i][j]])
                        apper[block[flag[tmp]][tmp][i][j]]++;
                    else
                        return false;
                }
                tmp++;
            }
        }
    }
    return true;
}

void dfs(int now, int sum)
{
    if (sum >= ans)
        return;
    if (now == 17)
    {
        ans = sum;
        return;
    }
    for (int i = 0; i <= 3; i++)
    {
        flag[now] = i;
        if (check(now))
            dfs(now + 1, sum + i);
    }
    flag[now] = 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char str[107];
        ans = 55;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < 16; i++)
        {
            scanf("%s", str);
            int cnt = i / 4 * 4;
            for (int j = 0; j < 16; j++)
            {
                if (str[j] > '9')
                    block[0][cnt + (j / 4) + 1][i % 4 + 1][j % 4 + 1] = str[j] - 'A' + 10;
                else
                    block[0][cnt + (j / 4) + 1][i % 4 + 1][j % 4 + 1] = str[j] - '0';
            }
        }

        for (int cnt = 1; cnt <= 16; cnt++) //预处理旋转90度
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    block[1][cnt][i][j] = block[0][cnt][5 - j][i];
                }
            }
        }
        for (int cnt = 1; cnt <= 16; cnt++) //预处理旋转180度
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    block[2][cnt][i][j] = block[0][cnt][5 - i][5 - j];
                }
            }
        }
        for (int cnt = 1; cnt <= 16; cnt++) //预处理旋转270度
        {
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 1; j <= 4; j++)
                {
                    block[3][cnt][i][j] = block[0][cnt][j][5 - i];
                }
            }
        }
        for (int i = 0; i <= 3; i++)
        {
            flag[1] = i;
            dfs(2, i);
        }
        printf("%d\n", ans);
    }
    return 0;
}