#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[1007], path[1007];

struct Mouse
{
    int w, s, idx;
} arr[1007];

bool cmp(const Mouse &a, const Mouse &b)
{
    if (a.s != b.s)
    {
        return a.s > b.s;
    }
    else
    {
        return a.w < b.w;
    }
}

void printpath(int i)
{
    if (path[i] == i)
    {
        cout << i << endl;
        return;
    }
    printpath(path[i]);
    cout << i << endl;
}

int main()
{
    int size = 1;
    while (cin >> arr[size].w >> arr[size].s)
    {
        arr[size].idx = size;
        dp[size] = 1;
        size++;
    }
    for (int i = 1; i < size; i++)
    {
        path[i] = i;
    }
    sort(arr + 1, arr + size, cmp);
    int ans = 0, ansmouse = 0;
    for (int i = 2; i < size; i++)
    {
        int maxn = 0, tmp;
        for (int j = 1; j < i; j++)
        {
            if (arr[j].w < arr[i].w && arr[j].s > arr[i].s)
            {
                if (dp[j] > maxn)
                {
                    maxn = dp[j];
                    tmp = arr[j].idx;
                }
            }
        }
        dp[i] = maxn + 1;
        if (maxn != 0)
        {
            path[arr[i].idx] = tmp;
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            ansmouse = arr[i].idx;
        }
    }
    if (ans == 1)
    {
        cout << "1\n1" << endl;
    }
    else
    {
        cout << ans << endl;
        printpath(ansmouse);
    }
    return 0;
}