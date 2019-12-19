#include <iostream>
using namespace std;

int cost[1100], bill[1100];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> bill[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (bill[ans] >= cost[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}