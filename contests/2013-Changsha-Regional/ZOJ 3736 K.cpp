#include <iostream>

using namespace std;

int n, arr[30], ans;
int link[6][10] = {{0, 2, 6, 12, 16, 18, 20, 22}, {1, 3, 7, 13, 17, 19, 21, 23}, {4, 5, 6, 7, 8, 9, 23, 22}, {10, 11, 12, 13, 14, 15, 21, 20}, {2, 3, 8, 14, 17, 16, 11, 5}, {0, 1, 9, 15, 19, 18, 10, 4}};
int area[6][4] = {{5, 11, 10, 4}, {8, 14, 15, 9}, {2, 3, 1, 0}, {16, 17, 19, 18}, {7, 13, 12, 6}, {23, 21, 20, 22}};
int block[6][4] = {0, 1, 2, 3, 4, 5, 10, 11, 6, 7, 12, 13, 8, 9, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};

int fun()
{
    int cnt = 0;
    for (int i = 0; i < 6; i++)
        if ((arr[block[i][0]] == arr[block[i][2]]) && (arr[block[i][0]] == arr[block[i][1]]) && (arr[block[i][2]] == arr[block[i][3]]))
            cnt++;
    return cnt;
}

void roll(int id, int choice)
{
    int next1 = (choice & 1 ? 6 : 2), next2 = (choice & 1 ? 3 : 1), brr[14];
    for (int i = 0; i < 8; i++)
        brr[i] = arr[link[id][i]];
    for (int i = 0; i < 4; i++)
        brr[i + 8] = arr[area[id][i]];
    for (int i = 0; i < 8; i++)
        arr[link[id][i]] = brr[(next1 + i) % 8];
    for (int i = 0; i < 4; i++)
        arr[area[id][i]] = brr[(next2 + i) % 4 + 8];
}

void dfs(int step)
{
    if (step == n)
        return;
    for (int i = 0; i < 6 && ans != 6; i++)
    {
        roll(i, 0);
        ans = max(ans, fun());
        dfs(step + 1);
        roll(i, 1);
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < 24; i++)
            scanf("%d", &arr[i]);
        ans = fun();
        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}