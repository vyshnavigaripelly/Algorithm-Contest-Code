#include <iostream>
#include <cstdio>

using namespace std;

int arr[200007], first[200007], cnt[200007];

int main()
{
    int n;
    cin >> n;
    int maxpos = 0, maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
        if (cnt[arr[i]] > maxn)
        {
            maxn = cnt[arr[i]];
            maxpos = arr[i];
        }
        if (first[arr[i]] == 0)
        {
            first[arr[i]] = i;
        }
    }
    printf("%d\n", n - maxn);
    for (int i = first[maxpos] - 1; i >= 1; i--)
    {
        printf("%d %d %d\n", (arr[i] < arr[i + 1] ? 1 : 2), i, i + 1);
        arr[i] = arr[i + 1];
    }
    for (int i = first[maxpos]; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            continue;
        }
        printf("%d %d %d\n", (arr[i + 1] < arr[i] ? 1 : 2), i + 1, i);
        arr[i + 1] = arr[i];
    }
    return 0;
}