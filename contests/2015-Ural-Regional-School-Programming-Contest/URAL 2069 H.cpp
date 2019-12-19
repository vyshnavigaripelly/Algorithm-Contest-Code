#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int col[100007], row[100007];

int main()
{
    int n, m, left, right, up, down, maxc = -1, maxr = -1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &col[i]);
        maxc = max(col[i], maxc);
        if (i == 0)
            left = col[i];
        if (i == n - 1)
            right = col[i];
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &row[i]);
        maxr = max(row[i], maxr);
        if (i == 0)
            up = row[i];
        if (i == m - 1)
            down = row[i];
    }
    cout << max({min({left, right, maxr}), min({up, down, maxc}), min(up, right), min(left, down)}) << endl;
    return 0;
}