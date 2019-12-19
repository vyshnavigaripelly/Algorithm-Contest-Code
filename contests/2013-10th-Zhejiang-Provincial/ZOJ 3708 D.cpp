#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, cnt = 0, start[505], end[505], arr[505][505];
        memset(arr, 0, sizeof(arr));
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> start[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> end[i];
        }
        for (int i = 0; i < m; i++)
        {
            if (arr[start[i]][end[i]] == 0)
            {
                cnt++;
                arr[start[i]][end[i]] = 1;
                arr[end[i]][start[i]] = 1;
            }
        }
        printf("%.3lf\n", 1.0 * cnt / n);
    }
    return 0;
}
