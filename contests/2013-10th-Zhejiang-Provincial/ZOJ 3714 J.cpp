#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, kid[500];
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> kid[i];
            kid[i + n] = kid[i];
        }
        int max = 0;
        for (int i = 0; i < 2 * n - m; i++)
        {
            int sum = 0;
            for (int j = i; j < m + i; j++)
            {
                sum += kid[j];
            }
            if (sum > max)
            {
                max = sum;
            }
        }
        cout << max << endl;
    }
    return 0;
}
