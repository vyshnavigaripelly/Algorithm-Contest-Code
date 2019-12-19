#include <iostream>

using namespace std;

int arr[1007], vis[2007];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        vis[k]++;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    while (true)
    {
        int flag = 1;
        for (int i = 0; i < m; i++)
        {
            if (vis[ans + arr[i]] != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}