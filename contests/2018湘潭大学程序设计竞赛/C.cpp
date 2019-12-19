#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt[105][105] = {0};
        cin >> n;
        while (n--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int i = x1 + 1; i <= x2; i++)
            {
                for (int j = y1 + 1; j <= y2; j++)
                {
                    cnt[i][j]++;
                }
            }
        }
        int max = 0;
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                if (cnt[i][j] > max)
                {
                    max = cnt[i][j];
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}