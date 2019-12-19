#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int arr[507][507];

int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int ans[507];
    int times = 7e4;
    while (times--)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = rand() % m;
            ans[i] = tmp + 1;
            sum ^= arr[i][tmp];
        }
        if (sum > 0)
        {
            cout << "TAK" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NIE" << endl;
    return 0;
}