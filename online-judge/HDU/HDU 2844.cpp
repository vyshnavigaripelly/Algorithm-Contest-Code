#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxnum = 107; // 物品最大个数
const int maxvol = 200007; // 背包最大容量

struct Item
{
    int value;
    int amount;
} arr[maxnum];

int dp[maxvol];
int num, vol;

// 01背包
void ZeroOnePack(int value)
{
    for (int i = vol; i >= value; i--)
    {
        dp[i] = max(dp[i], dp[i - value] + value);
    }
}

// 完全背包
void CompletePack(int value)
{
    for (int i = value; i <= vol; i++)
    {
        dp[i] = max(dp[i], dp[i - value] + value);
    }
}

// 多重背包
void MultiplePack(int value, int amount)
{
    if (vol <= amount * value) // 该物品足够装满背包，相当于可以取无限次，直到背包放不下为止
    {
        CompletePack(value);
        return;
    }
    else // 否则，转换成01背包
    {
        int k = 1;
        while (k < amount)
        {
            ZeroOnePack(k * value);
            amount = amount - k;
            k = 2 * k;
        }
        ZeroOnePack(amount * value);
    }
}

int main()
{
    int m;
    while (~scanf("%d %d", &num, &m) && (num && m))
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        vol = 0;
        for (int i = 1; i <= num; i++)
        {
            scanf("%d", &arr[i].value);
        }
        for (int i = 1; i <= num; i++)
        {
            scanf("%d", &arr[i].amount);
            vol += arr[i].amount * arr[i].value;
        }
        vol = min(vol, m);
        for (int i = 1; i <= num; i++)
        {
            MultiplePack(arr[i].value, arr[i].amount);
        }
        int ans = 0;
        for (int i = 1; i <= vol; i++)
        {
            if (dp[i] == i)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
