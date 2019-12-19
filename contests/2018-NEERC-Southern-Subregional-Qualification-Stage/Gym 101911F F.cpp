#include <iostream>

using namespace std;

char str[10];
int arr[30][1000007];
int sum[30][1000007];

void dfs(int pos, char str[], int num)
{
    if (pos == 6)
    {
        int d = abs(str[0] + str[1] + str[2] - str[3] - str[4] - str[5]);
        arr[d][num]++;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        str[pos] = i + '0';
        dfs(pos + 1, str, num * 10 + i);
        str[pos] = '\0';
    }
}

int main()
{
    char tmp[10];
    dfs(0, tmp, 0);
    for (int i = 0; i <= 27; i++)
    {
        for (int j = 0; j <= 999999; j++)
        {
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        int t = atoi(str);
        int d = abs(str[0] + str[1] + str[2] - (str[3] + str[4] + str[5]));
        int ans = 0;
        for (int j = 0; j < d; j++)
        {
            ans += sum[j][t - 1];
        }
        printf("%d\n", ans);
    }
    return 0;
}