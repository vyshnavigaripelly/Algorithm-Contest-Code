#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d[1001] = {0}, n, k, a[1001];
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 1; j <= 1000; j++)
            {
                if (j % a[i] == 0)
                {
                    d[j]++;
                }
            }
        }
        for (int i = 1; i <= 1000; i++)
        {
            if (d[i] >= k)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
