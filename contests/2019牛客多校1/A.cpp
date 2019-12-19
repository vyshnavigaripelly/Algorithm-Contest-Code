#include <iostream>
#include <stack>
#include <map>

using namespace std;

const int N = 100007;

int arr[N], brr[N];
int ansa[N], ansb[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &brr[i]);
        }
        stack<pair<int, int>> sa, sb;
        sa.push({0, -1});
        sb.push({0, -1});
        for (int i = 0; i < n; i++)
        {
            while (sa.top().first > arr[i])
            {
                sa.pop();
            }
            while (sb.top().first > brr[i])
            {
                sb.pop();
            }
            ansa[i] = sa.top().second;
            ansb[i] = sb.top().second;
            sa.push({arr[i], i});
            sb.push({brr[i], i});
        }
        int ans = 0;
        while (ans < n && ansa[ans] == ansb[ans])
        {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}